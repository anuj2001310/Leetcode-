void dfs(int node, int** isConnected, bool* visited, int n) {
    visited[node] = true;
    for (int j = 0; j < n; j++) {
        if (isConnected[node][j] == 1 && !visited[j]) {
            dfs(j, isConnected, visited, n);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int provinces = 0;
    bool* visited = (bool*)calloc(isConnectedSize, sizeof(bool));

    for (int i = 0; i < isConnectedSize; i++) {
        if (!visited[i]) {
            dfs(i, isConnected, visited, isConnectedSize);
            provinces++;
        }
    }
    free(visited);
    return provinces;
}