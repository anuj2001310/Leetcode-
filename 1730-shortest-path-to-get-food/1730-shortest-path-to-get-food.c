#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dist;
    int r;
    int c;
} Node;

int getFood(char** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int m = gridColSize[0];

    int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Visited array
    bool** vis = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++)
        vis[i] = (bool*)calloc(m, sizeof(bool));

    
    Node* q = (Node*)malloc(n * m * sizeof(Node));
    int front = 0, rear = 0;

    // Find starting point '*'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                q[rear++] = (Node){0, i, j};
                vis[i][j] = true;
                break;
            }
        }
        if (rear > 0)
            break;
    }

    while (front < rear) {
        Node curr = q[front++];

        if (grid[curr.r][curr.c] == '#') {
            free(q);
            for (int i = 0; i < n; i++)
                free(vis[i]);
            free(vis);
            return curr.dist;
        }

        for (int d = 0; d < 4; d++) {
            int nr = curr.r + dirs[d][0];
            int nc = curr.c + dirs[d][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                grid[nr][nc] != 'X') {

                vis[nr][nc] = true;
                q[rear++] = (Node){curr.dist + 1, nr, nc};
            }
        }
    }

    free(q);
    for (int i = 0; i < n; i++)
        free(vis[i]);
    free(vis);

    return -1;
}