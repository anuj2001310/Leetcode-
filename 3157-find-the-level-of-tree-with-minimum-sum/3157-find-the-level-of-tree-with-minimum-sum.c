/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <limits.h>

typedef struct TreeNode TreeNode;

TreeNode* q[1000001];
int front = -1, rear = -1;

int minimumLevel(struct TreeNode* root) {
    if (!root)
        return 0;

    int level = 1, ans = 1;
    long minSum = LLONG_MAX;

    q[++rear] = root;
    while (rear > front) {
        int n = rear - front;
        long currSum = 0;

        for (int i = 0; i < n; i++) {
            TreeNode* node = q[++front];
            currSum += node->val;

            if (node->left)
                q[++rear] = node->left;

            if (node->right)
                q[++rear] = node->right;
        }

        if (currSum < minSum) {
            minSum = currSum;
            ans = level;
        }

        level++;
    }

    return ans;
}