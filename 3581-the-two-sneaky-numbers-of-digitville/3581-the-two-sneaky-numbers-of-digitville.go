func getSneakyNumbers(nums []int) []int {
    n := len(nums)
    hash := make([]int, 102)
    ans := make([]int, 2)
    idx := 0
    for i := 0; i < n; i++ {
        hash[nums[i]]++
        if hash[nums[i]] == 2 {
            ans[idx] = nums[i]
            idx += 1
        }
    }
    return ans
}