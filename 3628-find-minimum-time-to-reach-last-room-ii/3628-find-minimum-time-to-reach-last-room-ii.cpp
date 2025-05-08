class State {
public:
    int r;
    int c;
    int dis;
    State(int r, int c, int dis) : r(r), c(c), dis(dis) {}
};
class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    const int inf = 0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<bool>> v(n, vector<bool>(m, false));

        d[0][0] = 0;

        auto cmp = [&](const auto& a, const auto& b) { 
            return a.dis > b.dis;
        };

        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        q.push(State(0, 0, 0));

        while (!q.empty()) {
            auto s = q.top();
            q.pop();

            if (v[s.r][s.c])
                continue;
            
            if (s.r == n - 1 && s.c == m - 1)
                break;

            v[s.r][s.c] = true;

            for (int i = 0; i < dirs.size(); i++) {
                int nr = s.r + dirs[i][0];
                int nc = s.c + dirs[i][1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;
                int dist = fmax(d[s.r][s.c], moveTime[nr][nc]) + (s.r + s.c) % 2 + 1;
                if (d[nr][nc] > dist) {
                    d[nr][nc] = dist;
                    q.push(State(nr, nc, dist));
                }
            }
        }
        return d[n - 1][m - 1];
    }
};