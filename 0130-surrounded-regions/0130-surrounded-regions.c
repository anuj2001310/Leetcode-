// BFS Solution in C Written by Bhatiji
int dirs[][4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

typedef struct pair {
    int first;
    int second;
} pair;

pair* new_pair(int first, int second) {
    pair* p = (pair*)malloc(sizeof(pair));
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

void solve(char** board, int boardSize, int* boardColSize) {
    int n = boardSize;
    int m = (*boardColSize);

    bool** vis = (bool**)calloc(sizeof(bool*), n);
    for (int i = 0; i < n; ++i)
        vis[i] = (bool*)calloc(sizeof(bool), m);
    
    queue* q = createQueue(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (board[i][j] == 'O') {
                    vis[i][j] = true;
                    push(q, new_pair(i, j));
                }
            }
        }
    }

    while (!isEmpty(q)) {
        struct pair* pr = pop(q);
        int r = pr->first;
        int c = pr->second;
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && !vis[nr][nc]) {
                push(q, new_pair(nr, nc));
                vis[nr][nc] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
        }
    }
}