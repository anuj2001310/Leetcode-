typedef long long ll;

long long removeZeros(long long n) {
    long long res = 0;
    int* ans = (int*)calloc(sizeof(int), 16);
    int returnSize = 15;
    for (; n; ) {
        int r = n % 10;
        n /= 10;
        if (r == 0)
            continue;
        ans[returnSize--] = r;
    }

    for (int i = 0; i < 16; ++i) {
        if (ans[i] == 0)
            continue;
        res = res * 10 + ans[i];
    }
    return res;
}