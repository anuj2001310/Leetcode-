public class Solution {
    public int MaxUniqueSplit(string s) {
        var rs = MaxUniqueSplit(0, new HashSet<string>(), s);
        return rs;
    }
    private int MaxUniqueSplit(int index, HashSet<string> set, string s) {
        var rs = 0;
        if (index >= s.Length) return rs;
        for (int i = index; i < s.Length; i++) {
            var part = s.Substring(index, i - index + 1);
            if (!set.Contains(part)) {
                set.Add(part);
                var rs0 = 1 + MaxUniqueSplit(i + 1, set, s);
                rs = Math.Max(rs, rs0);
                set.Remove(part);
            }
        }
        return rs;
    }
}