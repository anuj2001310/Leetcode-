func sumOfDig(num int) int {
    if num == 0 {
        return 0
    }
    return num % 10 + sumOfDig(num / 10)
}

func countLargestGroup(n int) int {
    sums := make([]int, 37)
    for i := 1; i <= n; i++ {
        sums[sumOfDig(i)]++
    }
    ans, max := 0, 0
    for i := 0; i < 37; i++ {
        if sums[i] > max {
            max = sums[i]
            ans = 1
        } else if sums[i] == max {
            ans += 1
        }
    }
    return ans
}