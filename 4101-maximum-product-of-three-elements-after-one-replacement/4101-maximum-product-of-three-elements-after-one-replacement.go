func maxProduct(nums []int) int64 {
    var mx1 int64
    var mx2 int64
    n := len(nums)

    for i := 0; i < n; i++ {
        var absNum int64
        if nums[i] < 0 {
            absNum = int64(-nums[i])
        } else {
            absNum = int64(nums[i])
        }

        if absNum > mx2 {
            if absNum > mx1 {
                mx2 = mx1
                mx1 = absNum
            } else {
                mx2 = absNum
            }
        }
    }
    return int64(mx1 * mx2 * 100000)
}