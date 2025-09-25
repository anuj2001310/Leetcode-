class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dpCurrent(*triangle.rbegin());
        vector<int> dpNew;
        for (int i = triangle.size() - 2; i >= 0; --i) {
            dpNew.assign(triangle[i].size(), 0);
            for (int j = 0; j < triangle[i].size(); ++j) {
                dpNew[j] = triangle[i][j] + min(dpCurrent[j], dpCurrent[j + 1]);
            }
            dpCurrent = dpNew;
            dpNew = vector<int>();
        }
        return dpCurrent[0];
    }
};