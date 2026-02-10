#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define INF std::numeric_limits<int>::max()
class Solution {
private:
    vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = size(rooms);
        int m = size(rooms[0]);
        queue<pair<int, pii>> q;
        vvb vis(n, vb(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            auto t = q.front().first;
            auto r = q.front().second.first;
            auto c = q.front().second.second;
            q.pop();

            rooms[r][c] = min(rooms[r][c], t);
            for (auto& dir : dirs) {
                auto nr = r + dir[0];
                auto nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && rooms[nr][nc] == INF) {
                    q.push({t + 1, {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
        }
    }
};