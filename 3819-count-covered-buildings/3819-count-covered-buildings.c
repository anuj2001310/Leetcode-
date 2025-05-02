int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
    int* x_min = (int*)calloc(sizeof(int), n + 1);
    int* x_max = (int*)calloc(sizeof(int), n + 1);
    
    int* y_min = (int*)calloc(sizeof(int), n + 1);
    int* y_max = (int*)calloc(sizeof(int), n + 1);

    for (int i = 0; i < n + 1; i++) {
        x_min[i] = INT_MAX;
        y_min[i] = INT_MAX;
    }

    for (int i = 0; i < n + 1; i++) {
        x_max[i] = INT_MIN;
        y_max[i] = INT_MIN;
    }
    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0], y = buildings[i][1];
        x_min[x] = fmin(x_min[x], y);
        x_max[x] = fmax(x_max[x], y);
        y_min[y] = fmin(y_min[y], x);
        y_max[y] = fmax(y_max[y], x);
    }
    
    int cnt = 0;
    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];
        if (y > x_min[x] && y < x_max[x] && x > y_min[y] && x < y_max[y])
            cnt++;
    }

    free(x_min), free(x_max), free(y_min), free(y_max);
    return cnt;
    
}