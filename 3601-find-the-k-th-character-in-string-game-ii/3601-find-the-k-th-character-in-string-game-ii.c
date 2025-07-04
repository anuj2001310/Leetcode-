char kthCharacter(long long k, int* operations, int operationsSize) {
    int ans = 0;
    k--;
    for (int i = (int)log2(k); i >= 0; i--) {
        if ((k >> i) & 1) {
            ans += operations[i];
        }
    }
    return 'a' + (ans % 26);
}