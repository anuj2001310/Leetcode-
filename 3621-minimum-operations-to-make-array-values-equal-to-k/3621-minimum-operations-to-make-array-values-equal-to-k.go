func minOperations(nums []int, k int) int {
    arr := make([]int, 101)
    for _, num := range nums {
        if num < k {
            return -1
        } else if num > k {
            arr[num]++
        }
    }
    cnt := 0
    for i := 0; i < 101; i++ {
        if arr[i] != 0 {
            cnt++
        }
    }
    return cnt
}