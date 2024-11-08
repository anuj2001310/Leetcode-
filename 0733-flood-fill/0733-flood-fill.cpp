class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<int>>& image, vector<vector<int>>& ans,
             int n, int m, int ini, int color) {
        ans[r][c] = color;
        for (int i = 0; i < dirs.size(); ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                image[nr][nc] == ini and ans[nr][nc] != color)
                dfs(nr, nc, image, ans, n, m, ini, color);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int ini = image[sr][sc];

        vector<vector<int>> ans = image;
        dfs(sr, sc, image, ans, n, m, ini, color);

        return ans;
    }
};