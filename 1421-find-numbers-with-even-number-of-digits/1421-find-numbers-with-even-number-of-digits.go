func findNumbers(nums []int) int {
    cnt := 0
    for _, num := range nums {
        size := 0
        for num > 0 {
            size++
            num /= 10
        }
        if size & 1 == 0 {
            cnt++
        }
    }
    return cnt
}