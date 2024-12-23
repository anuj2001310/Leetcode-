/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// BFS Solution in C Written by Bhatiji
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

typedef struct Queue {
    struct TreeNode** nodes; // Array of pointers to TreeNode
    int front;               // Index of the front element
    int rear;                // Index of the rear element
    int size;                // Current number of elements in the queue
    int capacity;            // Maximum number of elements the queue can hold
} queue;

queue* createQueue(int capacity) {
    queue* q = (queue*)malloc(sizeof(queue));
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = capacity - 1;
    q->nodes = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

bool isEmpty(queue* q) { 
    return q->size == 0;
}

bool isFull(queue* q) { 
    return q->size == q->capacity;
}

void push(queue* q, struct TreeNode* node) {
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % (q->capacity);
    q->nodes[q->rear] = node;
    q->size++;
}

struct TreeNode* pop(queue* q) {
    if (isEmpty(q))
        return NULL;

    struct TreeNode* node = q->nodes[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

void freeQueue(queue* q) {
    free(q->nodes);
    free(q);
}

int cmp(const void* a, const void* b) {
    pair* pa = (pair*)a;
    pair* pb = (pair*)b;
    return pa->first - pb->first;
}

int swaps(int* arr, int arrSize) {
    int num = 0;
    pair* temp = (pair*)malloc(arrSize * sizeof(pair));

    for (int i = 0; i < arrSize; i++) {
        temp[i].first = arr[i];
        temp[i].second = i;
    }
    /*
    // Before Sorting
    printf("Before Sorting Temp is :- ");
    for (int i = 0; i < arrSize; i++)
        printf("{%d, %d}, ", temp[i].first, temp[i].second);
    printf("\n");
    */
    qsort(temp, arrSize, sizeof(pair), cmp);

    /*
    // After Sorting
    printf("After Sorting Temp is :- ");
    for (int i = 0; i < arrSize; i++)
        printf("{%d, %d}, ", temp[i].first, temp[i].second);
    printf("\n");
    */

    for (int i = 0; i < arrSize; i++) {
        while (temp[i].second != i) {
            num++;
            int idx = temp[i].second;
            pair tempPair = temp[i];
            temp[i] = temp[idx];
            temp[idx] = tempPair;
        }
    }

    free(temp);
    return num;
}

int minimumOperations(struct TreeNode* root) {
    queue* q = createQueue(100001);
    int cnt = 0;
    push(q, root);
    while (!isEmpty(q)) {
        int n = q->size;
        int u = 0;
        int* arr = (int*)calloc(n, sizeof(int));
        while (u < n) {
            struct TreeNode* node = pop(q);
            arr[u] = node->val;
            if (node->left)
                push(q, node->left);
            if (node->right)
                push(q, node->right);
            u++;
        }
        cnt += swaps(arr, n);
        free(arr);
    }

    freeQueue(q);
    return cnt;
}