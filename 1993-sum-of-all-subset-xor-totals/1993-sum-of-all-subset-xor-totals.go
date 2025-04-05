func subsetXORSum(nums []int) int {
    n, c := len(nums), 0
    for _, num := range nums {
        c |= num
    }

    return c << (n - 1)
}