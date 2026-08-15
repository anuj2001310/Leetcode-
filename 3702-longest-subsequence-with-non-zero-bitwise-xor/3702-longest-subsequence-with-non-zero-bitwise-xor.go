func longestSubsequence(nums []int) int {
    n := len(nums)
    total_xor := 0
    for i := 0; i < n; i++ {
        total_xor ^= nums[i]
    }

    if total_xor != 0 {
        return n
    }

    for i := 0; i < n; i++ {
        if nums[i] != 0 {
            return n - 1
        }
    }
    return 0
}