/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

// BFS Solution in C
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

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int n = imageSize;
    int m = (*imageColSize);

    int initial = image[sr][sc];
    int** ans = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        ans[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; ++j)
            ans[i][j] = image[i][j];
    }

    queue* q = createQueue(n * m);
    push(q, new_pair(sr, sc));
    ans[sr][sc] = color;

    while (!isEmpty(q)) {
        struct pair* pr = pop(q);
        int r = pr->first;
        int c = pr->second;
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == initial && ans[nr][nc] != color) {
                push(q, new_pair(nr, nc));
                ans[nr][nc] = color;
            }
        }
    }

    freeQueue(q);
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return ans;
}