func totalNumbers(digits []int) int {
    ans := 0
    n := len(digits)
    vis := make([]bool, 1000)
    for i := 0; i < n; i++ {
        if digits[i] == 0 {
            continue
        }

        for j := 0; j < n; j++ {
            if j == i {
                continue
            }

            for k := 0; k < n; k++ {
                if k == j || k == i || digits[k] & 1 != 0 {
                    continue
                }

                digit := digits[i] * 100 + digits[j] * 10 + digits[k]

                if !vis[digit] {
                    vis[digit] = true
                    ans++
                }
            }
        }
    }
    return ans
}