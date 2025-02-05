func areAlmostEqual(s1 string, s2 string) bool {
    n := len(s1)
    cnt := 0
    a, b := make([]int, 26), make([]int, 26)
    for i := 0; i < n; i++ {
        idx1 := s1[i] - 'a'
        idx2 := s2[i] - 'a'
        a[idx1]++
        b[idx2]++
        if s1[i] != s2[i] {
            cnt++
        }
    }

    for i := 0; i < 26; i++ {
        if a[i] != b[i] {
            return false
        }
    }
    return cnt <=2
}