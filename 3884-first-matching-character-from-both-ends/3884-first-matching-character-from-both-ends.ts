function firstMatchingIndex(s: string): number {
    let n: number = s.length;
    for (let i: number = 0; 2 * i < n; i++) {
        if (s[i] == s[n - i - 1])
            return i;
    }
    return -1;
};