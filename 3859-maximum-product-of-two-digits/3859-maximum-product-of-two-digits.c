int maxProduct(int num) {
    int n = 0, m = 0;
    for (; num; ) {
        int r = num % 10;
        if (r >= n) {
            m = n;
            n = r;
        }
        else if (r > m)
            m = r;
        num /= 10;
    }
    return n * m;
}