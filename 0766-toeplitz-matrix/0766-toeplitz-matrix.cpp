class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int n = size(mat), m = size(mat[0]);
        unordered_map<int, unordered_set<int>> map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                map[i - j].insert(mat[i][j]);
        }

        auto it = map.begin();
        for (; it != map.end(); ++it) {
            if (size(it->second) != 1)
                return false;
        }
        return true;
    }
};