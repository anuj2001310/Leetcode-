class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> dp(m);

        for (int j = 1; j < n; ++j) {
            int leftTop = 0; // 1
            bool found = false;

            for (int i = 0; i < m; ++i) {
                int cur = -1;
                int nxtLeftTop = dp[i]; // next leftTop   1

                if (i - 1 >= 0 && leftTop != -1 &&
                    grid[i][j] > grid[i - 1][j - 1]) {
                    cur = max(cur, leftTop + 1);
                }
                if (dp[i] != -1 && grid[i][j] > grid[i][j - 1]) {
                    cur = max(cur, dp[i] + 1);
                }
                if (i + 1 < m && dp[i + 1] != -1 &&
                    grid[i][j] > grid[i + 1][j - 1]) {
                    cur = max(cur, dp[i + 1] + 1);
                }

                dp[i] = cur;
                res = max(res, dp[i]);
                found = found || (dp[i] != -1); // check if found in this col

                leftTop = nxtLeftTop;
            }
            if (!found)
                break;
        }

        return res;
    }
};