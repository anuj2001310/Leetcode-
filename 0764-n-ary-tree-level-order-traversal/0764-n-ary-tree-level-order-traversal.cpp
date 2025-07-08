/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        queue<Node*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                Node* child = q.front();
                q.pop();
                temp.push_back(child->val);
                for(auto node : child->children)
                    q.push(node);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};