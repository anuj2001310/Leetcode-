public class Solution {
    public int MaxScoreSightseeingPair(int[] values) {
        int n = values.Length;
        int maxScore = 0;
        int maxLeft = values[0];

        for (int j = 1; j < n; j++) {
            maxScore = Math.Max(maxScore, maxLeft + values[j] - j);
            maxLeft = Math.Max(maxLeft, values[j] + j);
        }
        return maxScore;
    }
}