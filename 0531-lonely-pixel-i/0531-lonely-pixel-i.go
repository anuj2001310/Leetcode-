func findLonelyPixel(p [][]byte) int {
    n, m := len(p), len(p[0])
    r, c := make([]int, n), make([]int, m)

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if p[i][j] == 'B' {
                r[i]++
                c[j]++
            }
        }
    }
    cnt := 0
    
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if p[i][j] == 'B' && r[i] == 1 && c[j] == 1 { 
                cnt++
            }
        }
    }
    return cnt
}