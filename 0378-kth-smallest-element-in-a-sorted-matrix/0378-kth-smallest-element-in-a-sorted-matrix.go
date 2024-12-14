import "container/heap"

func kthSmallest(matrix [][]int, k int) int {
	n := len(matrix)
	nextRowIdx := make([]int, n) // to track which cell have been pushed to pq
	nextColIdx := make([]int, n)
	var h IntHeap
	heap.Push(&h, [4]int{0, 0, matrix[0][0], 0})
	nextRowIdx[0]++
	nextColIdx[0]++
	for k > 1 {
		item := heap.Pop(&h).([4]int)
		r, c := item[0], item[1]

		if c+1 < n && r >= nextColIdx[c+1] {
			heap.Push(&h, [4]int{r, c + 1, matrix[r][c + 1], r + c + 1})
			nextRowIdx[r]++
			nextColIdx[c+1]++
		}
		if r+1 < n && c >= nextRowIdx[r+1] {
			heap.Push(&h, [4]int{r + 1, c, matrix[r + 1][c], r + c + 1})
			nextRowIdx[r+1]++
			nextColIdx[c]++
		}

		k--
	}
	return h[0][2]
}

type IntHeap [][4]int

func (h IntHeap) Len() int { 
    return len(h)
}
func (h IntHeap) Less(i, j int) bool {
	return h[i][2] < h[j][2] || (h[i][2] == h[j][2] && h[i][3] < h[j][3])
}
func (h IntHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x any) {
	*h = append(*h, x.([4]int))
}
func (h *IntHeap) Pop() any {
	old := *h
	n := len(old) - 1
	x := old[n]
	*h = old[:n]
	return x
}