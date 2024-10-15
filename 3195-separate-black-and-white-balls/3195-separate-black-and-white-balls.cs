public class Solution {
    public long MinimumSteps(string s) {
        long res = 0;
        long swap = 0;
        foreach (var ch in s) {
            if (ch == '1')
                swap++;
            else
                res += swap;
        }
        return res;
    }
}