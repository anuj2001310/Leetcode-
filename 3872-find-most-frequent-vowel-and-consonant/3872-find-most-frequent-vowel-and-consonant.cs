public class Solution {
    public int MaxFreqSum(string s) {
        var n = s.Length;
        var freq = new int[26];
        foreach (var ch in s)
            freq[ch - 'a']++;

        var v = 0;
        var c = 0;
        
        bool isVowel(char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }

        for (var i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (isVowel(s[i]))
                v = (freq[idx] > v ? freq[idx] : v);
            else
                c = (freq[idx] > c ? freq[idx] : c);
        }
        
        return c + v;
    }
}