class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> r(n, false);
        vector<bool> c(m, false);
        for (uint i = 0; i < n; i++) {
            for (uint j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    r[i] = true;
                    c[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (r[i] or c[j])
                    matrix[i][j] = 0;
            }
        }
    }
};