public class Solution {
    private bool v(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    public string TrimTrailingVowels(string s) {
        int n = s.Length;
        int id = n - 1;
        while (id >= 0) {
            if (!v(s[id]))
                break;
            id--;
        }
        return s.Substring(0, id + 1);
    }
}