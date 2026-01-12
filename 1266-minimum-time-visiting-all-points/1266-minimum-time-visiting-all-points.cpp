class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int i = points[0][0];
        int j = points[0][1];
        int ans = 0;

        for (int k = 1; k < n; k++) {
            int low = points[k][0];
            int high = points[k][1];
            ans += max(abs(i - low), abs(j - high));
            i = low;
            j = high;
        }
        return ans;
    }
};