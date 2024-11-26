func findChampion(n int, edges [][]int) int {
    inDeg := make([]int, n)
    for i := 0; i < len(edges); i++ {
        v := edges[i][1]
        inDeg[v]++
    }

    cnt, ans := 0, -1
    for i := 0; i < n; i++ {
        if inDeg[i] == 0 {
            cnt++
            ans = i
        }
    }
    if cnt == 1 {
        return ans
    }
    return -1
}