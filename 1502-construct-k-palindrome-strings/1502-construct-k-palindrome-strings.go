func canConstruct(s string, k int) bool {
    n := len(s)
    cnt := 0
    if n < k {
        return false
    }

    arr := make([]int, 26)
    for _, ch := range s {
        arr[ch - 'a']++
    }

    for i := 0; i < 26; i++ {
        if arr[i] & 1 != 0 {
            cnt++
        }
    }
    if cnt > k {
        return false
    }
    return true
}