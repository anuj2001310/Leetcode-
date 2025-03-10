func Min (x, y int) int {
    if x < y {
        return x
    }
    return y
}
func getMinDistance(nums []int, target int, start int) int {
    ans := math.MaxInt
    for idx, num := range nums {
        if num == target {
            ans = Min(ans, int(math.Abs(float64(idx - start))))
        }
    }
    return ans
}