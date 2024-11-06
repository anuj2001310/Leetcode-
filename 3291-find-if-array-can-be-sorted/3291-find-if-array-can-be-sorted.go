func count(n int) int {
    b := 0
    for n != 0 {
        b += n & 1
        n >>= 1
    }
    return b
}
func canSortArray(nums []int) bool {
    l := 0
    h := nums[0]
    bit := false
    for i := 1; i < len(nums); i++ {
        bit = (count(h) != count(nums[i]))
        if bit {
            l = h
        }
        if nums[i] > h {
            h = nums[i]
        }
        if nums[i] < l {
            return false
        } 
    }
    return true
}