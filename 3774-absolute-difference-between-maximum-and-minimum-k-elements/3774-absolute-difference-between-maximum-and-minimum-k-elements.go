func absDifference(nums []int, k int) int {
    n := len(nums)
    sort.Ints(nums)
    s, f := 0, 0

    for i:= 0; i < k; i++ {
        s += nums[i]
        f += nums[n - i - 1]
    }
    return f - s
}