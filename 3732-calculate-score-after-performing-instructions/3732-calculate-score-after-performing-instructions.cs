public class Solution {
    public long CalculateScore(string[] instructions, int[] values) {
        var n = values.Length;
        long sum = 0;
        var vis = new bool[n];
        for (int i = 0; i >= 0 && i < n && !vis[i]; ) {
            vis[i] = true;
            if (instructions[i].Equals("add")) {
                sum += values[i];
                ++i;
            } else
                i += values[i];
        }
        return sum;
    }
}