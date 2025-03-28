typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<int> ans(k);

        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

        vector<pair<int, int>> helpful;

        for (int i = 0; i < k; ++i)
            helpful.push_back({queries[i], i});

        sort(helpful.begin(), helpful.end());

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;
        int cnt = 0;

        for (int i = 0; i < k; ++i) {
            int thresh = helpful[i].first;
            int idx = helpful[i].second;

            while (!pq.empty() and pq.top().first < thresh) {
                auto top = pq.top();
                pq.pop();

                ++cnt;
                int val = top.first;
                int r = top.second.first;
                int c = top.second.second;

                // cout<<val<<"  ";
                for (int i = 0; i < dirs.size(); ++i) {
                    int nr = r + dirs[i][0];
                    int nc = c + dirs[i][1];

                    if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                        !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        pq.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
            ans[idx] = cnt;
        }
        return ans;
    }
};