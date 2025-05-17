class Solution {
    using vb = vector<bool>;
    using vvb = vector<vb>;

    using vi = vector<int>;
    using object = pair<int, pair<int, int>>;

private:
    vector<vi> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vvb vis(n, vb(m, false));

        priority_queue<object, vector<object>, greater<object>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto cost = pq.top().first;
            auto r = pq.top().second.first;
            auto c = pq.top().second.second;
            pq.pop();
            if (r == n - 1 and c == m - 1)
                return cost;
            if (vis[r][c])
                continue;
            vis[r][c] = true;
            for (int i = 0; i < dirs.size(); i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                    !vis[nr][nc]) {
                    int curr_cost =
                        fmax(cost, fabs(heights[r][c] - heights[nr][nc]));
                    pq.push({curr_cost, {nr, nc}});
                }
            }
        }
        return -1;
    }
};