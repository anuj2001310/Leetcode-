class Solution {
    private void help(int n, int[] freq) {
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            if ((mask & n) != 0)
                freq[i]++;
        }
    }

    public int largestCombination(int[] candidates) {
        int[] freq = new int[32];
        for (int ele : candidates)
            help(ele, freq);

        int ans = 0;
        for (int f : freq)
            ans = Math.max(ans, f);
        return ans;
    }
}