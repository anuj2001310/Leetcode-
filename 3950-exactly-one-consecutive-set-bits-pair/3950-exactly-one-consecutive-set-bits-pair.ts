function consecutiveSetBits(n: number): boolean {
    let cnt: number = 0, p: number = -1;
    for (; n > 0; n >>= 1) {
        let r: number = ((n & 1) != 0) ? 1 : 0;
        if (r == 1 && r == p)
            cnt++;
        p = r;
    }
    return cnt == 1;
};