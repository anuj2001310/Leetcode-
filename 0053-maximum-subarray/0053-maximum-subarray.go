func maxSubArray(nums []int) int {
    n := len(nums)
    ans := math.MinInt
    curr := 0
    for i := 0; i < n; i++ {
        curr += nums[i]
        if curr > ans {
            ans = curr
        }

        if curr < 0 {
            curr = 0
        }
    }
    return ans
}