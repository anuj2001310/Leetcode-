import "math"

func maxSubarrayLength(nums []int, k int) int {
    n := len(nums)
    hash := make(map[int]int)
    l, r, ans := 0, 0, math.MinInt

    for ; r < n; r++ {
        hash[nums[r]]++

        for hash[nums[r]] > k {
            hash[nums[l]]--
            l++
        }
        ans = max(ans, r - l + 1)
    }
    return ans
}