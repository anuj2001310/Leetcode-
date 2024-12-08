func constructTransformedArray(nums []int) []int {
    n := len(nums)
    var arr []int

    for i := 0; i < n; i++ {
        idx := (i + nums[i] % n + n) % n
        arr = append (arr, nums[idx])
    }
    return arr
}