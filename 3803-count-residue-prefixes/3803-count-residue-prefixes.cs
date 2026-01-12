public class Solution {
    public int ResiduePrefixes(string s) {
        var n = s.Length;
        int dis = 0, ans = 0;
        var freq = new int[26];

        for (var i = 0; i < n; ++i) {
            int ch = s[i] - 97;
            if (freq[ch] == 0)
                dis++;
            freq[ch]++;

            ans += ((dis == (i + 1) % 3) ? 1 : 0); 
        }
        return ans;
    }
}