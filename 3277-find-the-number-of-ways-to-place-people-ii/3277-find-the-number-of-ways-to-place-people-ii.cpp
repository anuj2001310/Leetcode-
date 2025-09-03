class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int ax = points[i][0];
            int ay = points[i][1];
            int k = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int bx = points[j][0];
                int by = points[j][1];
                if (by > ay)
                    continue;
                if (by > k) {
                    ans++;
                    k = by;
                }
            }
        }
        return ans;
    }
};