public class Solution {
    public string CompressedString(string word) {
        StringBuilder comp = new StringBuilder(word.Length);
        int cnt = 0;
        char prev = word[0];
        foreach (var c in word) {
            if (prev == c) {
                cnt++;
                if (cnt == 9) {
                    comp.Append(cnt);
                    comp.Append(prev);
                    cnt = 0;
                }
            }
            else{
                if (cnt > 0) {
                    comp.Append(cnt);
                    comp.Append(prev);
                }
                cnt = 1;
                prev = c;
            }
        }
        if (cnt > 0) {
            comp.Append(cnt);
            comp.Append(prev);
        }
        return comp.ToString();
    }
}