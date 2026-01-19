int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize, n = matColSize[0];
    int** P = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        P[i] = (int*)calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    int l = 1, r = (m < n ? m : n), ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int find = 0;
        for (int i = 1; i <= m - mid + 1; i++) {
            for (int j = 1; j <= n - mid + 1; j++) {
                int sum = P[i + mid - 1][j + mid - 1] - P[i - 1][j + mid - 1] -
                          P[i + mid - 1][j - 1] + P[i - 1][j - 1];
                if (sum <= threshold) {
                    find = 1;
                    break;
                }
            }
            if (find) break;
        }
        if (find) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    for (int i = 0; i <= m; i++) {
        free(P[i]);
    }
    free(P);
    return ans;
}