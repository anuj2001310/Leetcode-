public class Solution {
    public int PrefixCount(string[] words, string pref) {
        var cnt = 0;
        foreach (var word in words) {
            if (word.StartsWith(pref))
                cnt++;
        }
        return cnt;
    }
}