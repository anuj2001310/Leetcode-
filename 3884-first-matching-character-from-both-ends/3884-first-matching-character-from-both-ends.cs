public class Solution {
    public int FirstMatchingIndex(string s) {
        var n = s.Length;
        int i = 0, j = n - 1;
        while (i <= j) {
            if (s[i++] == s[j--])
                return i - 1;
        }
        return -1;
    }
}