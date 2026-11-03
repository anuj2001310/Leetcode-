func minMoves(nums []int) int {
    ans := 0
    max := math.MinInt
    for _, num := range nums {
        if num > max {
            max = num
        }
    }

    for _, num := range nums {
        ans += max - num
    }
    return ans
}