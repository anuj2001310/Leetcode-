func pathExistenceQueries(n int, nums []int, maxDiff int, queries [][]int) []bool {
    q, cnt := len(queries), 0
    comp := make([]int, n)
    for i := 1; i < n; i++ {
        if nums[i] - nums[i - 1] <= maxDiff {
            comp[i] = cnt
        } else {
            cnt++
            comp[i] = cnt
        }
    }
    ans := make([]bool, q)
    for i, query := range queries {
        u := query[0]
        v := query[1]
        ans[i] = (comp[u] == comp[v])
    }
    return ans
}