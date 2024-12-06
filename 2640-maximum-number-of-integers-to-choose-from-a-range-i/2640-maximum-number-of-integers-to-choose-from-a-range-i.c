int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    bool* hash = (bool*)calloc(sizeof(bool), 10001);
    for (int i = 0; i < bannedSize; ++i)
        hash[banned[i]] = true;

    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!hash[i]) {
            sum += i;
            if (sum <= maxSum)
                cnt++;
            else {
                free(hash);
                return cnt;
            }
        } else
            continue;
    }
    free(hash);
    return cnt;
}