public class Solution {
    public int ReverseDegree(string s) {
        int sum = 0, i = 0;
        foreach (var ch in s)
            sum += ((26 - ch + 'a') * (++i));
        return sum;
    }
}