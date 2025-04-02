func maximumTripletValue(nums []int) int64 {
    n := len(nums)
    var ans int64 = 0
    var dmax int64 = 0
    var imax int64 = 0
    for i := 0; i < n; i++ {
        a := dmax * int64(nums[i])
        d := imax - int64(nums[i])
        if a > ans {
            ans = a
        }
        if d > dmax {
            dmax = d
        }
        if int64(nums[i]) > imax {
            imax = int64(nums[i])
        }
    }
    return ans
}