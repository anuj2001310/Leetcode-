typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(vector<vector<int>>& grid, int i, int j, int val, int k, vector<vector<vector<int>>>& dp) {
        if (i == 0 and j == 0) {
            if ((val ^ grid[0][0]) == k)
                return 1;
            else
                return 0;
        }

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j][val] != -1)
            return dp[i][j][val];

        int up = solve(grid, i - 1, j, val ^ grid[i][j], k, dp);
        int left = solve(grid, i, j - 1, val ^ grid[i][j], k, dp);

        return dp[i][j][val] = (up + left) % mod;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vvvi dp(n, vvi(m, vi(16, -1)));

        int ans = solve(grid, grid.size() - 1, grid[0].size() - 1, 0, k, dp);
        return ans % mod;
    }
};