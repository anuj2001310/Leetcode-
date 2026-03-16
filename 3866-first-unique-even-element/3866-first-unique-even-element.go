func firstUniqueEven(nums []int) int {
    n := len(nums)
    mp := make([]int, 101)

    for _, num := range nums {
        mp[num]++
    }

    for i := 0; i < n; i++ {
        if nums[i] & 1 == 0 && mp[nums[i]] == 1 {
            return nums[i]
        }
    }
    return -1
}