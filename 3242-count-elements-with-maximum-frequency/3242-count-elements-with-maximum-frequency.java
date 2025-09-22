class Solution {
    public int maxFrequencyElements(int[] nums) {
        int n = nums.length;
        var freq = new int[101];
        int cnt = 0, max = 0;

        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
            max = Math.max(max, freq[nums[i]]);
        }
        for (int r = 0; r < 101; ++r) {
            if (freq[r] == 0)
                continue;
            cnt += (freq[r] == max) ? 1 : 0;
        }
        return cnt * max;
    }
}