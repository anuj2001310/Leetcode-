/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

// BFS Solution in C
int dirs[][4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

typedef struct pair {
    int dis;
    int first;
    int second;
} pair;

pair* new_pair(int dis, int first, int second) {
    pair* p = (pair*)malloc(sizeof(pair));
    p->dis = dis;
    p->first = first;
    p->second = second;
    return p;
}
typedef struct queue {
    struct pair** arr;
    int capacity;
    int front;
    int rear;
    int size;
} queue;

queue* createQueue(int capacity) {
    queue* q = (queue*)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = capacity - 1;
    q->size = 0;
    q->arr = (struct pair**)malloc(sizeof(struct pair*) * capacity);
    return q;
}

bool isEmpty(queue* q) { 
    return q->size == 0;
}

bool isFull(queue* q) { 
    return q->size == q->capacity;
}

void push(queue* q, struct pair* p) {
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % (q->capacity);
    q->arr[q->rear] = p;
    q->size++;
}

struct pair* pop(queue* q) {
    if (isEmpty(q))
        return NULL;

    struct pair* p = q->arr[q->front];
    q->front = (q->front + 1) % (q->capacity);
    q->size--;
    return p;
}

void freeQueue(queue* q) {
    free(q->arr);
    free(q);
}

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance,
                int entranceSize) {
    int n = mazeSize;
    int m = *mazeColSize;

    bool** vis = (bool**)calloc(n, sizeof(bool*));
    for (int i = 0; i < n; i++)
        vis[i] = (bool*)calloc(m, sizeof(bool));

    int u = entrance[0], v = entrance[1];
    vis[u][v] = true;

    queue* q = createQueue(n * m);
    push(q, new_pair(0, u, v));

    while (!isEmpty(q)) {
        struct pair* pr = pop(q);
        int dis = pr->dis;
        int r = pr->first;
        int c = pr->second;

        if ((r == 0 || r == n - 1 || c == 0 || c == m - 1) &&
            (r != u || c != v)) {
            for (int i = 0; i < n; i++) {
                free(vis[i]);
            }
            freeQueue(q);
            return dis;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                maze[nr][nc] == '.') {
                push(q, new_pair(dis + 1, nr, nc));
                vis[nr][nc] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        free(vis[i]);
    freeQueue(q);
    return -1;
}