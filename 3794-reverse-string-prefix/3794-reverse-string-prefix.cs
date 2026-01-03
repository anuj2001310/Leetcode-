public class Solution {
    public string ReversePrefix(string s, int k) {
        char[] ch = s.ToCharArray();
        int f = 0, l = k - 1;
        while (f <= l) {
            var c = ch[f];
            ch[f] = ch[l];
            ch[l] = c;
            f++;
            l--;
        }
        return new string(ch);
    }
}