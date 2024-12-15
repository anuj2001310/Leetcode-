// BFS Solution in C Written by Bhatiji
int dirs[][4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

typedef struct pair {
    int time;
    int first;
    int second;
} pair;

pair* new_pair(int time, int first, int second) {
    pair* p = (pair*)malloc(sizeof(pair));
    p->time = time;
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
int maxDistance(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = (*gridColSize);
    int cnt = 0;
    int time = -1;

    bool** vis = (bool**)calloc(sizeof(bool*), n);
    for (int i = 0; i < n; ++i)
        vis[i] = (bool*)calloc(sizeof(bool), m);
    
    queue* q = createQueue(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j]) {
                cnt++;
                vis[i][j] = true;
                push(q, new_pair(0, i, j));
            }
        }
    }
    if (cnt == 0 || cnt == n * m) {
        freeQueue(q);
        free(vis);
        return -1;
    }

    while (!isEmpty(q)) {
        pair* p = pop(q);
        int t = p->time;
        int r = p->first;
        int c = p->second;
        time = fmax(time, t);
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                vis[nr][nc] = true;
                push(q, new_pair(t + 1, nr, nc));
            }
        }
    }
    freeQueue(q);
    free(vis);

    return time;    
}