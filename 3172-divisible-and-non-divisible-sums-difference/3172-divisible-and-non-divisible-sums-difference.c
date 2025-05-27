int differenceOfSums(int n, int m) {
    int sum0 = 0, sum1 = 0;
    for (int i = 1; i <= n; i++) {
        if (i % m != 0)
            sum0 += i;
        else
            sum1 += i;
    }
    return sum0 - sum1;
}