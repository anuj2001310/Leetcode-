class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), gap = 0, res = 0;

        for (int i = 0; i < n; i++) {
            int left, right;
            left = (i == 0) ? 0 : endTime[i - 1];
            right = (i == n - 1) ? eventTime : startTime[i + 1];

            if (gap >= endTime[i] - startTime[i]) {
                res = max(res, right - left);
            } else
                res = max(res, right - left - (endTime[i] - startTime[i]));

            int currGap =
                (i == 0) ? startTime[i] : startTime[i] - endTime[i - 1];
            gap = max(gap, currGap);
        }

        gap = 0;
        for (int i = n - 1; i >= 0; i--) {
            int left, right;
            left = (i == 0) ? 0 : endTime[i - 1];
            right = (i == n - 1) ? eventTime : startTime[i + 1];

            if (gap >= endTime[i] - startTime[i]) {
                res = max(res, right - left);
            } else
                res = max(res, right - left - (endTime[i] - startTime[i]));

            int currGap = (i == n - 1) ? eventTime - endTime[i]
                                       : startTime[i + 1] - endTime[i];
            gap = max(gap, currGap);
        }

        return res;
    }
};