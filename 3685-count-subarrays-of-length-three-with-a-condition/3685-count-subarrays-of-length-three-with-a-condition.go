func countSubarrays(nums []int) int {
    n := len(nums)
    cnt := 0
    for i := 1; i < n - 1; i++ {
        if 2 * (nums[i - 1] + nums[i + 1]) == nums[i] {
            cnt++
        }
    }
    return cnt
}