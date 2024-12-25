/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct TreeNode TreeNode;

 typedef struct queue {
    TreeNode** arr;
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
    q->arr = (TreeNode**)malloc(sizeof(TreeNode*) * capacity);
    return q;
}

bool isEmpty(queue* q) { 
    return q->size == 0;
}

bool isFull(queue* q) { 
    return q->size == q->capacity; 
}

void push(queue* q, TreeNode* p) {
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % (q->capacity);
    q->arr[q->rear] = p;
    q->size++;
}

TreeNode* pop(queue* q) {
    if (isEmpty(q))
        return NULL;

    TreeNode* p = q->arr[q->front];
    q->front = (q->front + 1) % (q->capacity);
    q->size--;
    return p;
}

void freeQueue(queue* q) {
    free(q->arr);
    free(q);
}
int* largestValues(struct TreeNode* root, int* returnSize) {
    int* res = (int*)calloc((1 << 14), sizeof(int));
    *returnSize = 0;

    if (!root)
        return res;

    queue* q = createQueue(1 << 14);
    push (q, root);
    
    while (!isEmpty(q)) {
        int n = q->size;
        int num = INT_MIN;
        for (uint i = 0; i < n; i++) {
            TreeNode* f = pop(q);
            num = fmax(num, f->val);
            if (f->left)
                push(q, f->left);
            if (f->right)
                push(q, f->right);
        }
        res[(*returnSize)++] = num;
    }
    freeQueue(q);
    return res;
}