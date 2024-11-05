class Solution {
public:
    // Basically this ques. asks to raotate a image by 90 deg
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        // Transepose of a matrix first
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j)
                swap(mat[i][j], mat[j][i]);
        }

        // Now Reverse Each Row to get desire result
        for (uint i = 0; i < n; ++i) {
            for (uint j = 0; j < (n / 2); ++j)
                swap(mat[i][j], mat[i][n - j - 1]);
        }
    }
};