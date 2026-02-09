func dominantIndices(nums []int) int {
    n := len(nums)
    s := 0
    for _, num := range nums {
        s += num
    }
    c := 0
    for i := 0; i < n - 1; i++ {
        s -= nums[i]
        l := n - i - 1
        if int64(nums[i]) > int64(s / l) {
            c++
        }
    }
    return c
}