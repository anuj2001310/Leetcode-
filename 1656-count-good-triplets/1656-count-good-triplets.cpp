class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (fabs(arr[i] - arr[j]) > a)
                    continue;
                for (int k = j + 1; k < n; ++k) {
                    if (fabs(arr[j] - arr[k]) > b)
                        continue;
                    if (fabs(arr[k] - arr[i]) <= c)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};