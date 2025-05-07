using pii = pair<int, int>;
using pipii = pair<int, pii>;

class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<bool>> vis(m, vector<bool>(m, false));

        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

        int curr_time = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            curr_time = pq.top().first;
            auto r = pq.top().second.first;
            auto c = pq.top().second.second;
            pq.pop();

            if (r == n - 1 and c == m - 1)
                return curr_time;

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    if (curr_time >= moveTime[nr][nc])
                        pq.push({curr_time + 1, {nr, nc}});
                    else
                        pq.push({moveTime[nr][nc] + 1, {nr, nc}});
                    //st.insert({nr, nc});
                }
            }
        }
        return -1;
    }
};