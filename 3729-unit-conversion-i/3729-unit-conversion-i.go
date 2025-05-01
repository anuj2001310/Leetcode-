func baseUnitConversions(conversions [][]int) []int {
    mod := 1000_000_000 + 7

    n := len(conversions) + 1

    ans := make([]int,n)
    for i := 0; i < n; i++ {
        ans[i] = -1
    }
    
    egs := make([][][2]int,n)
    for i := range conversions {
        u, v, w := conversions[i][0], conversions[i][1], conversions[i][2]
        egs[u] = append(egs[u],[2]int{v, w})
    }

    qu := []int {0}
    ans[0] = 1
    for len(qu) > 0 {
        fr := qu[0]
        qu = qu[1: ]
        for i := range egs[fr] {
            t,w := egs[fr][i][0],egs[fr][i][1]
            if ans[t] != -1 {
                continue
            }
            ans[t] = ans[fr] * w % mod
            qu = append(qu,t)
        }
    }
    
    return ans
}