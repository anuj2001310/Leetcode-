/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;

void swap(int* x, int* y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
void change(Node* left, Node* right, int l) {
    if (!left || !right)
        return;
    if (l & 1) {
        swap(&left->val, &right->val);
    }
    change(left->left, right->right, l + 1);
    change(left->right, right->left, l + 1);
    return;
}
struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    change(root->left, root->right, 1);
    return root;
}