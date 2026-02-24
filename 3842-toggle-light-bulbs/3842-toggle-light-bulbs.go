func toggleLightBulbs(bulbs []int) []int {
    n := len(bulbs)
    freq := make([]bool, 101)

    for i := 0; i < n; i++ {
        if freq[bulbs[i]] {
            freq[bulbs[i]] = false
        } else {
            freq[bulbs[i]] = true
        }
    }
    ans := make([]int, 0)

    for i := 0; i < 101; i++ {
        if freq[i] {
            ans = append(ans, i)
        }
    }
    return ans
}