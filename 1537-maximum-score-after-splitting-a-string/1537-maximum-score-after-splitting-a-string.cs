public class Solution {
    public int MaxScore(string s) {
        int ones = 0;
        foreach (char ch in s)
            if (ch == '1')
                ones++;
            
        
        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.Length - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            
            ans = Math.Max(ans, zeros + ones);
        }
        
        return ans;
    }
}