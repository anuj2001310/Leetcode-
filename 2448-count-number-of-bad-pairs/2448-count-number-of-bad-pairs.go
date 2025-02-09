func countBadPairs(nums []int) int64 {
    mp := make(map[int]int)
    var bad int64

    for i := 0; i < len(nums); i++ {
        diff := i - nums[i]

        good := mp[diff]
        bad += (int64(i - good))

        mp[diff] = good + 1

    }
    return bad

}