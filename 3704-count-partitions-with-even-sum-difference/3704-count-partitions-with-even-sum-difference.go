func countPartitions(nums []int) int {
    n, left, cnt := len(nums), 0, 0
    sum := 0
    for _, num := range nums {
        sum += num
    }
    for i := 0; i < n - 1; i++ {
        left += nums[i]
        temp := sum - 2 * left
        if temp & 1 == 0 {
            cnt++
        }
    }
    return cnt
}