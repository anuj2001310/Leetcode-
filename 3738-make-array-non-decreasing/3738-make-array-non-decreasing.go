func maximumPossibleSize(nums []int) int {
    n, cnt, num := len(nums), 1, nums[0]
    for i := 1; i < n; i++ {
        if nums[i] >= num {
            cnt++
            num = nums[i]
        }
    }
    return cnt
}