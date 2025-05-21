class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> row(n, false), col(m, false);
        for (uint i = 0; i < n; ++i) {
            for (uint j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] or col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};