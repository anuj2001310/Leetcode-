int chalkReplacer(int* chalk, int chalkSize, int k) {
    long long tot = 0;
    for (int i = 0; i < chalkSize; ++i)
        tot += chalk[i];

    int complete_rounds = k % tot;
    for (int i = 0; i < chalkSize; ++i) {
        if (complete_rounds < chalk[i])
            return i;
        complete_rounds -= chalk[i];
    }
    return -1;
}