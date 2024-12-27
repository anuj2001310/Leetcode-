class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;
        int ans = Integer.MIN_VALUE;
        int ind = 0;
        for (int i = 1; i < n; i++) {
            ans = Math.max(ans, values[ind] + values[i] - Math.abs(ind - i));
            if (values[i] + i > values[ind] + ind)
                ind = i;
        }
        return ans;

    }
}