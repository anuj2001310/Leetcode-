func partitionLabels(s string) []int {
    arr := make([]int, 26)

    var ans []int
    for i, ch := range s {
        idx := int(ch - 97)
        arr[idx] = i
    }
    p, l := -1, -1
    for i, ch := range s {
        idx := int(ch - 97)
        if arr[idx] > l {
            l = arr[idx]
        }
        if i == l {
            ans = append(ans, (i - p))
            p = i
        }
    }
    return ans
}