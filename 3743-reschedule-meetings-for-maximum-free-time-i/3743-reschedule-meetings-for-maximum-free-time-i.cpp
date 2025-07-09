class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> gaps(n + 1);
        gaps[0] = startTime[0];
        for (int i = 1; i < n; ++i) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }
        gaps[n] = eventTime - endTime[n - 1];

        long long windowSum = 0;
        int windowSize = k + 1;
        for (int i = 0; i < windowSize && i < gaps.size(); ++i)
            windowSum += gaps[i];

        long long ans = windowSum;
        for (int i = windowSize; i < gaps.size(); ++i) {
            windowSum += gaps[i] - gaps[i - windowSize];
            ans = max(ans, windowSum);
        }

        return ans;
    }
};