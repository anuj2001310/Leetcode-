public class Solution {
    public bool CanConstruct(string s, int k) {
        var n = s.Length;
        if (n < k)
            return false;
        var cnt = 0;
        var freq = new int[26];
        foreach (var ch in s)
            freq[ch - 'a']++;
        
        for (var i = 0; i < 26; i++) {
            if ((freq[i] & 1) != 0)
                cnt++;
        }

        if (cnt > k)
            return false;

        return true;
    }
}