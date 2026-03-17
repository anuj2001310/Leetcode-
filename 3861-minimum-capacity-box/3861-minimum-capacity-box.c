int minimumIndex(int* capacity, int n, int itemSize) {
    int ans = -1;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (capacity[i] >= itemSize && capacity[i] < min)
            ans = i, min = capacity[i];
    }
    return ans;
}