func numEquivDominoPairs(dominoes [][]int) int {
    hash := make([]int, 100)
    cnt := 0
    for _, pair := range dominoes {
        u, v := pair[0], pair[1]
        num := 0
        if u > v {
            num = v * 10 + u
        } else {
            num = u * 10 + v;
        }
        cnt += hash[num]

        hash[num]++
    }
    return cnt
}