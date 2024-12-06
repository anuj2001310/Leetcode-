func maxCount(banned []int, n int, maxSum int) int {
    hash := make([]bool, 10001)

    for _, num := range banned {
        hash[num] = true
    }

    sum, cnt := 0, 0
    for i := 1; i <= n; i++ {
        if !hash[i] {
            sum += i

            if sum <= maxSum {
                cnt++
            } else {
                return cnt
            }
        } else {
            continue
        }
    }
    return cnt
}