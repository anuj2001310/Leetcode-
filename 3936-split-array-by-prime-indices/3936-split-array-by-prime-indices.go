func splitArray(nums []int) int64 {
    isPrime := func(num int) bool{
        if num <= 1 {
            return false
        }
        for i := 2; i <= int(math.Sqrt(float64(num))); i++ {
            if num % i == 0 {
                return false
            }
        }
        return true
    }
    var sumA int64
    var sumB int64
    n := len(nums)
    for i := 0; i < n; i++ {
        if isPrime(i) {
            sumA += int64(nums[i])
        } else {
            sumB += int64(nums[i])
        }
    }
    return int64(math.Abs(float64(sumA) - float64(sumB)))
}