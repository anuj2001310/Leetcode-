public class Solution {
    public string ProcessStr(string s) {
        var sb = new StringBuilder();
        int n = s.Length;
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (Char.IsLower(ch)) {
                sb.Append(ch);
                continue;
            }
            if (ch == '*' && sb.Length > 0)
                sb.Remove(sb.Length - 1, 1);
            else if (ch == '#')
                sb.Append(sb);
            else if (ch == '%') {
                int l = 0, r = sb.Length - 1;
                while (l < r) {
                    char tmp = sb[l];
                    sb[l] = sb[r];
                    sb[r] = tmp;
                    l++; r--;
                }
            }
        }
        return sb.ToString();
    }
}