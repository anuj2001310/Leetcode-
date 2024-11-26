int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    int inDeg[n] = {};
    for (int i = 0; i < edgesSize; ++i) {
        int v = edges[i][1];
        inDeg[v]++;
    }
    int ans = -1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (inDeg[i] == 0) {
            ++cnt;
            ans = i;
        }
    }
    return cnt == 1 ? ans : -1;
}