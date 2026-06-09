bool consecutiveSetBits(int n) {
    int cnt = 0, p = -1;
    for (; n > 0; n >>= 1) {
        int r = ((n & 1) != 0) ? 1 : 0;
        if (r == 1 && r == p)
            cnt++;
        p = r;
    }
    return cnt == 1;
}