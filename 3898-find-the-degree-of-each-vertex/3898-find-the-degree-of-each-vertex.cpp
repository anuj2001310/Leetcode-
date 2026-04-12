class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = size(matrix);
        vector<int> outdegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {

                    outdegree[i]++;
                    outdegree[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
            outdegree[i] /= 2;
        return outdegree;
    }
};