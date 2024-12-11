class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int[] freq = new int[100001];
        int x_max = 0, x_min = 0;
        for (int x : nums) {
            freq[x]++;
            x_max = Math.max(x_max, x);
            x_min = Math.min(x_min, x);
        }
        int cnt = 0, maxCnt = 0;
        for (int l = x_min, r = x_min; r <= x_max; r++) {
            cnt += freq[r];
            while (r - l > 2 * k) {
                cnt -= freq[l];
                l++;
            }
            maxCnt = Math.max(maxCnt, cnt);
        }
        return maxCnt;
    }
}