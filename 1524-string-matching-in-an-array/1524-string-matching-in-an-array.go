func stringMatching(words []string) []string {
    st := make(map[string] struct{})
    n := len(words)

    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if i != j {
                if strings.Contains(words[i], words[j]) {
                    st[words[j]] = struct{}{}
                }
            }
        }
    }


    ans := make([]string, 0)
    for str := range st {
        ans = append(ans, str)
    }

    return ans
    
}