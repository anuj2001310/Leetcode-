class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans1 = INT_MAX;
        for (int i = 0; i < n; i++) {
            int dur = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                int choose = max(dur, waterStartTime[j]);
                ans1 = min(ans1, choose + waterDuration[j]);
            }
        }
        int ans2 = INT_MAX;
        for (int i = 0; i < m; i++) {
            int dur = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < n; j++) {
                int choose = max(dur, landStartTime[j]);
                ans2 = min(ans2, choose + landDuration[j]);
            }
        }
        return min(ans1, ans2);
    }
};