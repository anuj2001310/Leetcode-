#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure for dynamic array (vector-like)
typedef struct {
    int* arr;
    int size;
    int capacity;
} Vector;

// Structure for queue
typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// Vector functions
void initVector(Vector* v, int capacity) {
    v->arr = (int*)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void pushVector(Vector* v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (int*)realloc(v->arr, v->capacity * sizeof(int));
    }
    v->arr[v->size++] = val;
}

// Queue functions
void initQueue(Queue* q, int capacity) {
    q->arr = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
}

void enqueue(Queue* q, int val) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->arr = (int*)realloc(q->arr, q->capacity * sizeof(int));
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeue(Queue* q) {
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

bool isEmpty(Queue* q) { return q->size == 0; }

int countCompleteComponents(int n, int** edges, int edgesSize,
                            int* edgesColSize) {
    // Create adjacency list
    Vector* adj = (Vector*)malloc(n * sizeof(Vector));
    for (int i = 0; i < n; i++)
        initVector(&adj[i], 2);

    // Build the graph
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        pushVector(&adj[u], v);
        pushVector(&adj[v], u);
    }

    int cnt = 0;
    bool* vis = (bool*)calloc(n, sizeof(bool));
    Vector comp;
    initVector(&comp, n);
    Queue q;
    initQueue(&q, n);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            comp.size = 0; // Clear component vector
            vis[i] = true;
            enqueue(&q, i);

            // BFS to find component
            while (!isEmpty(&q)) {
                int node = dequeue(&q);
                pushVector(&comp, node);

                for (int j = 0; j < adj[node].size; j++) {
                    int neigh = adj[node].arr[j];
                    if (!vis[neigh]) {
                        vis[neigh] = true;
                        enqueue(&q, neigh);
                    }
                }
            }

            // Check if component is complete
            bool flag = true;
            for (int j = 0; j < comp.size; j++) {
                if (adj[comp.arr[j]].size != comp.size - 1) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cnt++;
        }
    }

    // Cleanup
    for (int i = 0; i < n; i++)
        free(adj[i].arr);
    
    free(adj);
    free(vis);
    free(comp.arr);
    free(q.arr);

    return cnt;
}
