func bits(num int) int {
    bit := 0
    for num > 0 {
        num &= (num - 1)
        bit++
    }
    return bit
}

func sumIndicesWithKSetBits(nums []int, k int) int {
    sum := 0
    for i := 0; i < len(nums); i++ {
        if bits(i) == k {
            sum += nums[i]
        }
    }
    return sum
}