public class Solution {
    public int MinChanges(string s) {
        var cnt = 0;
        for (var i = 0; i < s.Length; i += 2)
            if (s[i + 1] != s[i])
                cnt++;
        return cnt;
    }
}