class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        array<int, 100001> freq = {};
        int xMax = 0, xMin = 1e6;
        for (int x : nums) {
            freq[x]++;
            xMax = fmax(x, xMax);
            xMin = fmin(x, xMin);
        }
        int cnt = 0, maxCnt = 0;
        for (int l = xMin, r = xMin; r <= xMax; r++) {
            cnt += freq[r];
            while (r - l > 2 * k) {
                cnt -= freq[l];
                l++;
            }
            maxCnt = fmax(maxCnt, cnt);
        }
        return maxCnt;
    }
};