package main

import (
	"fmt"
)

// ListNode represents a node in the queue
type Node struct {
	row, col, cost int
	next           *Node
}

// Queue represents a linked-list-based queue
type Queue struct {
	front, rear *Node
	size        int
}

// CreateNode creates a new ListNode
func CreateNode(row, col, cost int) *Node {
	return &Node{row: row, col: col, cost: cost, next: nil}
}

// CreateQueue creates a new Queue
func CreateQueue() *Queue {
	return &Queue{front: nil, rear: nil, size: 0}
}

// Enqueue adds a node to the rear of the queue
func (q *Queue) Enqueue(row, col, cost int) {
	newNode := CreateNode(row, col, cost)
	if q.rear == nil {
		q.front = newNode
        q.rear = newNode
	} else {
		q.rear.next = newNode
		q.rear = newNode
	}
	q.size++
}

// Unshift adds a node to the front of the queue
func (q *Queue) Unshift(row, col, cost int) {
	newNode := CreateNode(row, col, cost)
	if q.front == nil {
		q.front = newNode
        q.rear = newNode
	} else {
		newNode.next = q.front
		q.front = newNode
	}
	q.size++
}

// Dequeue removes and returns a node from the front of the queue
func (q *Queue) Dequeue() *Node {
	if q.front == nil {
		return nil
	}
	node := q.front
	q.front = q.front.next
	if q.front == nil {
		q.rear = nil
	}
	q.size--
	return node
}

// IsEmpty checks if the queue is empty
func (q *Queue) IsEmpty() bool {
	return q.size == 0
}

// IsInBounds checks if the position is within the grid bounds
func IsInBounds(r, c, m, n int) bool {
	return r >= 0 && r < m && c >= 0 && c < n
}

// MinimumObstacles finds the minimum obstacles encountered in a grid
func minimumObstacles(grid [][]int) int {
	m, n := len(grid), len(grid[0])

	// Directions: right, left, down, up
	directions := [4][2]int{
		{0, 1}, // right
		{0, -1}, // left
		{1, 0},  // down
		{-1, 0}, // up
	}

	// Create a queue for BFS
	q := CreateQueue()
	q.Enqueue(0, 0, 0)  // Start at (0, 0) with cost 0
	grid[0][0] = -1      // Mark as visited

	// BFS loop
	for !q.IsEmpty() {
		node := q.Dequeue()
		r, c, cost := node.row, node.col, node.cost

		// If we've reached the bottom-right corner
		if r == m-1 && c == n-1 {
			return cost
		}

		// Explore all 4 possible directions
		for _, dir := range directions {
			nr, nc := r+dir[0], c+dir[1]
			if IsInBounds(nr, nc, m, n) && grid[nr][nc] != -1 {
				if grid[nr][nc] == 1 {
					q.Enqueue(nr, nc, cost+1) // Cell has obstacle, add to back
				} else {
					q.Unshift(nr, nc, cost) // Free cell, add to front
				}
				grid[nr][nc] = -1 // Mark as visited
			}
		}
	}

	return 0 // If no valid path found
}

