func Max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func canJump(nums []int) bool {
    n := len(nums)
    mx := 0
    for i := 0; i < n; i++ {
        if i > mx {
            return false
        }
        mx = Max(mx , i + nums[i])
    }
    return true
}