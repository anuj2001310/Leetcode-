func getMaximumXor(nums []int, maximumBit int) []int {
    n := len(nums)
    b := (1 << maximumBit) - 1
    xor := 0
    ans := make([]int, n)
    
    for _, num := range nums {
        xor ^= num
    }

    for i := 0; i < n; i++ {
        ans[i] = xor ^ b
        xor ^= nums[n - i - 1]
    }
    return ans
}