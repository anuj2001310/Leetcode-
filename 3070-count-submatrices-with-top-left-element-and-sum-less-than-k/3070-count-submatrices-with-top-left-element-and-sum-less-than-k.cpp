class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int countSubMatrix = 0;
        int tempSum = 0;
        int maxFound = false;

        int m = grid.size();
        int n = grid[0].size();
        vector<int> tempBuffer;
        if (m == 0 || n == 0)
            return 0;
        
        tempSum = 0;
        for (int j = 0; j < n; j++) {
            tempBuffer.push_back(grid[0][j]);
            tempSum += grid[0][j];
            if (tempSum <= k)
                countSubMatrix++;
        }

        for (int i = 1; i < m; i++) {
            tempSum = 0;
            for (int j = 0; j < n; j++) {
                tempBuffer[j] += grid[i][j];
                tempSum += tempBuffer[j];
                if (tempSum <= k)
                    countSubMatrix++;
            }
        }

        return countSubMatrix;
    }
};