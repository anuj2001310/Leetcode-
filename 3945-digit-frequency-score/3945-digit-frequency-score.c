int digitFrequencyScore(int n) {
    return (n == 0) ? 0 : (n % 10 + digitFrequencyScore(n / 10));
}