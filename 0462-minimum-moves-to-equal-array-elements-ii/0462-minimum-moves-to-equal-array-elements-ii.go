func minMoves2(nums []int) int {
    n := len(nums)
    fabs := func(x int) int {
        if x < 0 {
            return -x
        }
        return x
    }
    
    sort.Ints(nums)
    m := nums[n >> 1]
    s := 0
    for i := 0; i < n; i++ {
        s += fabs(nums[i] - m)
    }
    return s
}