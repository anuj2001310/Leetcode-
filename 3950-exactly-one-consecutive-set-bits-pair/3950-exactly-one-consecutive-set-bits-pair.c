bool consecutiveSetBits(int n) {
    int c = 0, p = -1;
    for (; n; n >>= 1) {
        int r = (n & 1);
        if (r && r == p)
            c++;
        p = r;
    }
    return c == 1;
}