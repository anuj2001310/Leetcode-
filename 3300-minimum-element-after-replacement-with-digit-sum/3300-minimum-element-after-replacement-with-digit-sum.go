func minElement(nums []int) int {
    ans := math.MaxInt
    for _, num := range nums {
        cur := 0
        for num > 0 {
            cur += num % 10
            num /= 10
        }
        ans = min(ans, cur)
    }
    return ans
}