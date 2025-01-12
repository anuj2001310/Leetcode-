class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int cnt = 0;
        int n = grid.size(); //, m = grid[0].length;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                for (int j = grid[i].size() - 1; j >= 0; j--) {
                    if ((cnt & 1) == 0)
                        ans.push_back(grid[i][j]);
                    cnt++;
                }
            } else {
                for (int j = 0; j < grid[i].size(); j++) {
                    if ((cnt & 1) == 0)
                        ans.push_back(grid[i][j]);
                    cnt++;
                }
            }
        }
        return ans;
    }
};