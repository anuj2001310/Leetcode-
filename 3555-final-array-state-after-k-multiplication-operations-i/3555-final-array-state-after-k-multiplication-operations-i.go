func getFinalState(nums []int, k int, multiplier int) []int {
    n := len(nums)
    for i := 0; i < k; i++ {
        ans, idx := nums[0], 0
        for j := 0; j < n; j++ {
            if nums[j] < ans {
                ans = nums[j]
                idx = j
            }
        }
        nums[idx] *= multiplier
    }
    return nums
}