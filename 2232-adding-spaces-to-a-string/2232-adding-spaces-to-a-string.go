func addSpaces(s string, spaces []int) string {
    a := make([]uint8, 0, len(s) + len(spaces))
    for i, j := 0, 0; i < len(s); i++ {
        if j < len(spaces) && spaces[j] == i {
            a = append(a, ' ')
            j++
        }
        a = append(a, s[i])
    }
    return string(a)
}