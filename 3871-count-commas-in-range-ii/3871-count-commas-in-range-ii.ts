function countCommas(n: number): number {
    let ans: number = 0;
    let base: number = 1000;

    while (base <= n) {
        ans += (n - base + 1);
        base *= 1000;
    }
    return ans;
};