type MaxHeap [][2]int // list of tuples like this (1, 2) where 1 is number, 2 is count of occurrences

func (h MaxHeap) Len() int {
	return len(h)
}

func (h MaxHeap) Less(i, j int) bool {
	return h[i][1] > h[j][1]
}

func (h MaxHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *MaxHeap) Push(item interface{}) {
	*h = append(*h, item.([2]int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n - 1]
	*h = old[: n - 1]
	return x
}

func topKFrequent(nums []int, k int) []int {
	counts := map[int]int{}
	for _, num := range nums {
		counts[num]++
	}

	countHeap := &MaxHeap{}
	for key, val := range counts {
		*countHeap = append(*countHeap, [2]int{key, val})
	}
	heap.Init(countHeap)

	result := []int{}
	for i := 0; i < k; i++ {
		result = append(result, heap.Pop(countHeap).([2]int)[0])
	}

	return result
}