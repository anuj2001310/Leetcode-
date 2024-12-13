func findScore(nums []int) int64 {
    var ans int64 = 0
    n := len(nums)
    for i := 0; i < n; i += 2 {
        i0 := i
        for i + 1 < n && nums[i] > nums[i+1] {
            i++
        }
        for j := i; j >= i0; j -= 2 {
            ans += int64(nums[j])
        }
    }
    return ans
}