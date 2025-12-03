func subarraySum(nums []int, k int) int {
    n := len(nums)
    cnt, sum, r := 0, 0, 0
    hash := make(map[int]int)
    hash[sum] = 1
    for r < n {
        sum += nums[r];
        if key, v := hash[sum - k]; v {
            cnt += key
        }
        hash[sum]++
        r++
    }
    return cnt
}