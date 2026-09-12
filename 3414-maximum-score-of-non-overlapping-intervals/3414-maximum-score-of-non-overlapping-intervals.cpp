class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<int, 4>> a;
        for (int i = 0; i < n; i++)
            a.push_back({intervals[i][1], intervals[i][0], intervals[i][2], i});

        sort(a.begin(), a.end());

        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));

        vector<vector<vector<int>>> indices(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++) {
            int left = a[i - 1][1];
            int weight = a[i - 1][2];
            int originalindex = a[i - 1][3];

            int p = 0;
            int low = 0;
            int high = i - 2;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (a[mid][0] < left) {
                    p = mid + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            for (int j = 1; j <= 4; j++) {
                dp[i][j] = dp[i - 1][j];
                indices[i][j] = indices[i - 1][j];
                long long takeScore = dp[p][j - 1] + weight;

                vector<int> takeIndices = indices[p][j - 1];
                takeIndices.push_back(originalindex);

                sort(takeIndices.begin(), takeIndices.end());
                if (takeScore > dp[i][j] ||
                    (takeScore == dp[i][j] && takeIndices < indices[i][j])) {
                    dp[i][j] = takeScore;
                    indices[i][j] = takeIndices;
                }
            }
        }

        return indices[n][4];

        // TC -> O(nlogn + nk^2) as k = 4 -> O(nlogn)
    }
};