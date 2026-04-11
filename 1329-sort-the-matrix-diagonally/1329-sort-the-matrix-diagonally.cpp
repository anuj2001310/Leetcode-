class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;

        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < m; ++j) {
                int diff = i - j;
                map[diff].push(mat[i][j]);
            }
        }

        for (int  i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int diff = i - j;
                auto ele = map[diff].top();
                map[diff].pop();
                mat[i][j] = ele;
            }
        }
        return mat;
    }
};