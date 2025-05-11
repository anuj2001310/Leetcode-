bool threeConsecutiveOdds(int* arr, int n) {
    int cnt = 0, mask = (1 << 1);
    for (int i = 0; i < n; ++i) {
        if (arr[i] & 1)
            cnt++;
        else
            cnt = 0;
        if ((cnt & 1) && (mask & cnt))
            return true;
    }
    return false;
}