class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans = 0;
        int n = grid.size(), m = grid[0].size();

        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < n; ++i) {
            sort(grid[i].rbegin(), grid[i].rend());
            for (int j = 0; j < m and limits[i]; j++)
                pq.push(grid[i][j]), limits[i]--;
        }
        while (k-- and !pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};