class Solution {
    using pq = priority_queue<int, vector<int>>;
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pq> h (n);
        for (int i = 0; i < n; ++i) {
            for (auto& ele : grid[i])
                h[i].push(ele);
        }
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                auto ele = h[j].top();
                h[j].pop();
                num = max(num, ele);
            }

            ans += num;
        }
        return ans;
    }
};