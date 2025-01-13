public class Solution {
    public int MinimumLength(string s) {
        var n = s.Length;
        var freq = new int[26];
        foreach (var ch in s)
            freq[ch - 'a']++;
        
        var res = 0;
        for (var i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] > 2)
                freq[s[i] - 'a'] -= 2;
        }

        foreach (var f in freq)
            res += f;
        return res;
    }
}