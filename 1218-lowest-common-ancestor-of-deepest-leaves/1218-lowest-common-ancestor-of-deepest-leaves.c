/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
typedef struct Pair {
    TreeNode* node;
    int depth;
} pair;

pair* init(TreeNode* root, int depth) {
    pair* p = (pair*)malloc(sizeof(pair));
    p->node = root;
    p->depth = depth;
    return p;
}

pair* dfs(TreeNode* root) {
    if (root == NULL)
        return init(NULL, 0);

    pair* left = dfs(root->left);
    pair* right = dfs(root->right);

    if (left->depth > right->depth)
        return init(left->node, left->depth + 1);

    if (left->depth < right->depth)
        return init(right->node, right->depth + 1);

    return init(root, left->depth + 1);
}
struct TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return dfs(root)->node;
}