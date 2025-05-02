class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> x_min(n + 1, INT_MAX), x_max(n + 1, INT_MIN);
        vector<int> y_min(n + 1, INT_MAX), y_max(n + 1, INT_MIN);
        for (auto& building : buildings) {
            int x = building[0], y = building[1];
            x_min[x] = min(x_min[x], y);
            x_max[x] = max(x_max[x], y);
            y_min[y] = min(y_min[y], x);
            y_max[y] = max(y_max[y], x);
        }
        int cnt = 0;
        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            if (y > x_min[x] and y < x_max[x] and x > y_min[y] and x < y_max[y])
                cnt++;
        }
        return cnt;
    }
};