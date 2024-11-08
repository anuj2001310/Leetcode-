class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int ini = image[sr][sc];

        vector<vector<int>> ans = image;
        queue<pair<int, int>> q;

        q.push({sr, sc});
        ans[sr][sc] = color;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < dirs.size(); ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                    image[nr][nc] == ini and ans[nr][nc] != color) {
                    ans[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};