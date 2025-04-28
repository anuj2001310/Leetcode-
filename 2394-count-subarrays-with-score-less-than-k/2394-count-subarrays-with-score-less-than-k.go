func countSubarrays(nums []int, k int64) int64 {
    n, l := len(nums), 0
    var res, cnt, sum int64
    res = 0
    cnt = 0
    sum = 0
    for r := 0; r < n; r++ {
        sum += int64(nums[r])
        cnt++
        for sum * cnt >= k {
            sum -= int64(nums[l])
            l++
            cnt--
        }
        res += cnt;
    }
    return res
}