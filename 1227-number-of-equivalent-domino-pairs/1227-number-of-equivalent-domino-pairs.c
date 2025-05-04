int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int* map = (int*)calloc(sizeof(int), 100);
    int cnt = 0;
    for (int i = 0; i < dominoesSize; ++i) {
        int u = dominoes[i][0];
        int v = dominoes[i][1];
        int num = (u > v) ? v * 10 + u : u * 10 + v;
        cnt += map[num];

        map[num]++;
    }
    free(map);
    return cnt;
}
