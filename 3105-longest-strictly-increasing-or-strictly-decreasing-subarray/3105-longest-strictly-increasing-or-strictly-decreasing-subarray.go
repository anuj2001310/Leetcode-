func Max (x, y int) int {
    if x > y {
        return x
    }
    return y
}

func longestMonotonicSubarray(nums []int) int {
    n := len(nums)
    inc, dec := 1, 1
    mx := 1
    for i := 1; i < n; i++ {
        //Increasing Sequence
        if nums[i] > nums[i - 1] {
            inc++
            dec = 1
        } else if (nums[i] < nums[i - 1]) {
            //Decreasing Sequence
            inc = 1
            dec++
        } else {
            inc = 1
            dec = 1
        }
        
        mx = Max(mx, Max(inc, dec))
    }
    return mx
}