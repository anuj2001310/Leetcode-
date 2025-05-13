func minDeletion(s string, k int) int {
    freq := make([]int, 26)
    dis := 0
    for _, ch := range s {
        idx := int(ch - 'a')
        if freq[idx] == 0 {
            dis++
        }
        freq[idx]++
    }
    
    if k >= dis {
        return 0
    }
    
    del := 0
    sort.Ints(freq)

    j := 0
    for i := 0; i < 26 && j < dis - k; i++ {
        if freq[i] != 0 {
            del += freq[i]
            j++
        }
    }
    return del
}