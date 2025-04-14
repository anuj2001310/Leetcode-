

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int cnt = 0;
    int n = arrSize;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; ++j) {
            if (fabs(arr[i] - arr[j]) <= a) {
                for (int k = j + 1; k < n; ++k) {
                    if (fabs(arr[j] - arr[k]) <= b &&
                        fabs(arr[i] - arr[k]) <= c)
                        ++cnt;
                }
            }
        }
    }
    return cnt;
}