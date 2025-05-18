func smallestIndex(nums []int) int {
    n := len(nums)
    for i := 0; i < n; i++ {
        num, sum := nums[i], 0
        for num > 0 {
            sum += num % 10
            if sum > i{
                break
            }
            num /= 10
        }
        if (sum == i){
            return i
        }
    }
    return -1
}