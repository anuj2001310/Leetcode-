bool isBalanced(char* num) {
    int sum = 0;
    for (int i = 0; i < strlen(num); ++i) {
        int t = num[i] - '0';
        if (i & 1)
            sum += t;
        else
            sum -= t;
    }
    return !sum;
}