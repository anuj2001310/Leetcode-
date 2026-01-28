func minimumPrefixLength(nums []int) int {
    for i := len(nums) - 1; i > 0; i-- {
        if nums[i] <= nums[i - 1] {
            return i
        }
    }
    return 0
}