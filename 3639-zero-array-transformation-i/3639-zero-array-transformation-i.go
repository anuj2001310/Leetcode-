func isZeroArray(nums []int, queries [][]int) bool {
    n := len(nums)
    del := make([]int, n + 1)
    
    for _, q := range queries {
        l := q[0]
        r := q[1]
        del[l]++
        del[r + 1]--
    }
    
    for i := 1; i <= n; i++ {
        del[i] += del[i - 1]
    }
    
    for i := 0; i < n; i++ {
        if del[i] < nums[i] {
            return false
        }
    }
    return true
}