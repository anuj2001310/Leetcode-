public class Solution {
    public string FindValidPair(string s) {
        var freq = new int[10];
        int n = s.Length;
        foreach (var ch in s)
            freq[ch - '0']++;
        
        string ans = "";
        for (int i = 1; i < n; i++) {
            int cur = s[i] - '0';
            int pre = s[i - 1] - '0';
            if (pre == freq[pre] && cur == freq[cur] && cur != pre)
                return ans + pre + cur;
        }
        return "";
    }
}