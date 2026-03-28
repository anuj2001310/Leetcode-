class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n - 1;
        while (r < m && c > -1) {
            if (matrix[r][c] < target)
                r++;
            else if (matrix[r][c] > target)
                c--;
            else
                return true;
        }

        return false;
    }
};