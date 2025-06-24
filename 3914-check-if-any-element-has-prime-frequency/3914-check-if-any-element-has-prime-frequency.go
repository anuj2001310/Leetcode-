func checkPrimeFrequency(nums []int) bool {
    isPrime := func(num int) bool {
        if num <= 1 {
            return false
        }
        for i := 2; i * i <= num; i++ {
            if num % i == 0 {
                return false
            }
        }
        return true
    }
    
    freq := make([]int, 101)
    
    for _, num := range nums {
        freq[num]++
    }

    for i := 0; i < 101; i++ {
        if freq[i] == 0 {
            continue
        }
        
        if isPrime(freq[i]) {
            return true
        }
    }
    return false
}