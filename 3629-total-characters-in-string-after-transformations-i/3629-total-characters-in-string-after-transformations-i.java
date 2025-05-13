class Solution {
    final int MOD = 1_000_000_007;

    public int lengthAfterTransformations(String s, int t) {
        int ans = 0;
        long[] freq = new long[26];

        for (char ch : s.toCharArray())
            freq[ch - 'a']++;

        for (; t >= 26; t -= 26) {
            long z = freq[25];

            for (int i = 25; i > 0; i--)
                freq[i] = (freq[i] + freq[i - 1]) % MOD;

            freq[0] = (freq[0] + z) % MOD;
            freq[1] = (freq[1] + z) % MOD;
        }

        for (int i = 0; i < 26; i++)
            ans = (int) ((ans + freq[i]) % MOD);

        for (int i = 26 - t; i < 26; i++)
            ans = (int) ((ans + freq[i]) % MOD);

        return ans;
    }
}