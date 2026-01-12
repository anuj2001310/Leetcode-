class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 1; i < n; i++) {
            int diffx = abs(points[i][0] - points[i - 1][0]);
            int diffy = abs(points[i][1] - points[i - 1][1]);

            ans += max(diffx, diffy);
        }
        return ans;
    }
};