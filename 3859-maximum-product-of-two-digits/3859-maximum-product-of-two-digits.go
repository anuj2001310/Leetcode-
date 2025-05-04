func maxProduct(num int) int {
    n, m := 0, 0
    for num > 0 {
        r := num % 10
        num /= 10
        
        if r >= n {
            m = n
            n = r
        } else if r > m {
            m = r
        }
    }
    return n * m
}