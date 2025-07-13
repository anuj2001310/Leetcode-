func processStr(s string) string {
     result := []rune{}
    
    for _, char := range s {
        if char >= 'a' && char <= 'z' { // If lowercase letter
            result = append(result, char)
        } else if char == '*' { // Remove last character if exists
            if len(result) > 0 {
                result = result[:len(result)-1]
            }
        } else if char == '#' { // Duplicate current result
            result = append(result, result...)
        } else if char == '%' { // Reverse current result
            for i, j := 0, len(result)-1; i < j; i, j = i+1, j-1 {
                result[i], result[j] = result[j], result[i]
            }
        }
    }
    
    return string(result)
}