func putMarbles(weights []int, k int) int64 {
    n := len(weights)
    p := make([]int, n - 1)
    for i := 0; i < n - 1; i++ {
        p[i] += (weights[i] + weights[i + 1])
    }
    sort.Ints(p)
    
    //sort.Slice(p, func(i, j int) bool {return i < j})
    //fmt.Println(p)
    var ans int64
    //fmt.Println(ans)
    for i := 0; i < k - 1; i++ {
        ans += int64(p[n - i - 2] - p[i])
    } 
    return ans
}