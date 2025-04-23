int countLargestGroup(int n) {
    int sums[37] = {};

    int sumOfDig(int num) {
        return (num == 0 ? 0 : (num % 10) + sumOfDig(num / 10));
    }

    for (int i = 1; i <= n; ++i)
        sums[sumOfDig(i)]++;

    int cnt = 0, max = 0;

    for (int i = 0; i < 37; i++)
        ((sums[i] > max) ? (max = sums[i], cnt = 1) : (sums[i] == max) ? ++cnt : 0);
        
    return cnt;
}