func Max (x, y int) int {
    if x > y {
        return x
    }
    return y
}
func Min (x, y int) int {
    if x < y {
        return x
    }
    return y
}

func countSubarrays(nums []int, minK int, maxK int) int64 {
    n := len(nums)
    left_bnd, last_min, last_max := -1, -1, -1
    var cnt int64
    cnt = 0
    for i := 0; i < n; i++ {
        if nums[i] >= minK && nums[i] <= maxK {
            if nums[i] == minK {
                last_min = i
            }
            if nums[i] == maxK {
                last_max = i
            }
            cnt += int64(Max(0, Min(last_min, last_max) - left_bnd))
        } else {
            left_bnd = i
            last_min = -1
            last_max = -1
        }
    }
    return cnt
}