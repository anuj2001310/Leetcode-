func repeatedNTimes(nums []int) int {
    length := len(nums)
    hash := make([]bool, 10001)

    for i := 0; i < length; i++ {
        if hash[nums[i]] == true {
            return nums[i]
        } else {
            hash[nums[i]] = true
        }
    }
    return -1
}