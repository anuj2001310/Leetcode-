public class Solution {
    public int VowelConsonantScore(string s) {
        int c = 0 , v = 0;
        var vow = "aeiou";
        foreach (var ch in s) {
            if (vow.Contains(ch))
                v += 1;
            else if (ch >= 'a' && ch <= 'z' && !vow.Contains(ch))
                c += 1;
        }
        if (c == 0)
            return 0;
        return v / c;
    }
}