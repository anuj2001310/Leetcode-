func findMaxConsecutiveOnes(nums []int) int {
    temp := 0
    ans := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] == 1 {
            temp++
            ans = max(ans, temp)
        } else {
            temp = 0
        }
    }
    return ans
}