typedef long long ll;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        ll res = LLONG_MAX;
        ll top_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        ll bottom_sum = 0;
        for (int i = 0; i < m; ++i) {
            top_sum -= grid[0][i];
            res = fmin(res, fmax(top_sum, bottom_sum));
            bottom_sum += grid[1][i];
        }
        return res;
    }
};