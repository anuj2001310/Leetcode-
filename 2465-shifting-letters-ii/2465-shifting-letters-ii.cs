public class Solution {
    public string ShiftingLetters(string s, int[][] shifts) {
        var n = s.Length;
        int[] prefix = new int[n + 1];

        for (int i = 0; i < shifts.Length; i++) {
            int st = shifts[i][0];
            int e = shifts[i][1];
            int d = shifts[i][2];

            prefix[st] += (2 * d - 1);
            prefix[e + 1] -= (2 * d - 1);
        }

        var curr = 0;
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < n; i++) {
            curr = (curr + prefix[i]) % 26;
            char ch = (char) ('a' + (s[i] - 'a' + curr + 26) % 26);
            sb.Append(ch);
        }
        return sb.ToString();
    }
}