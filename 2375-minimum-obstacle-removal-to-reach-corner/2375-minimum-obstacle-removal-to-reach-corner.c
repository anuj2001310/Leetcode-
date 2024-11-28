#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Directions: right, left, down, up
int dirs[][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// Node for the Queue (Linked List Implementation)
typedef struct Node {
    int row;
    int col;
    int cost;
    struct Node* next;
} Node;

// Queue implementation (Linked List based)
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int row, int col, int cost) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->cost = cost;
    newNode->next = NULL;
    return newNode;
}

// Queue functions
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int row, int col, int cost) {
    Node* newNode = createNode(row, col, cost);
    if (q->rear == NULL)
        q->front = q->rear = newNode;
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

void unshift(Queue* q, int row, int col, int cost) {
    Node* newNode = createNode(row, col, cost);
    if (q->front == NULL)
        q->front = q->rear = newNode;
    else {
        newNode->next = q->front;
        q->front = newNode;
    }
    q->size++;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
        
    q->size--;
    return temp;
}

bool isEmpty(Queue* q) { 
    return q->size == 0;
}

// Function to check if coordinates are within bounds
bool isInBounds(int r, int c, int m, int n) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

// Function to find the minimum number of obstacles using BFS
int minimumObstacles(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = (*gridColSize);
    // Create a queue for BFS
    Queue* dq = createQueue();
    enqueue(dq, 0, 0, 0); // Start at (0, 0) with cost 0
    grid[0][0] = -1;      // Mark as visited

    // BFS loop
    while (!isEmpty(dq)) {
        Node* node = dequeue(dq);
        int r = node->row;
        int c = node->col;
        int cost = node->cost;
        free(node);

        // If we've reached the bottom-right corner
        if (r == m - 1 && c == n - 1) {
            return cost; // Return the number of obstacles encountered
        }

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (isInBounds(nr, nc, m, n) && grid[nr][nc] != -1) {
                if (grid[nr][nc] == 1)
                    enqueue(dq, nr, nc, cost + 1); // Cell has obstacle, add to back
                else
                    unshift(dq, nr, nc, cost); // Free cell, add to front
            
                grid[nr][nc] = -1; // Mark as visited
            }
        }
    }

    return 0; // If no valid path found
}

// Helper function to create a 2D grid
int** createGrid(int m, int n) {
    int** grid = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
    }
    return grid;
}

// Helper function to free a 2D grid
void freeGrid(int** grid, int m) {
    for (int i = 0; i < m; i++)
        free(grid[i]);
    free(grid);
}
