class Solution {
    int dp[][];

    private int ways(char[] s, char[] t, int i, int j) {
        if (j == t.length)
            return 1;
        if (i == s.length)
            return 0;
        if (s.length - i < t.length - j)
            return 0; // not possible 

        if (dp[i][j] != -1)
            return dp[i][j];
        int sum = 0;
        // include 
        if (s[i] == t[j])
            sum += ways(s, t, i + 1, j + 1);

        // not include 
        sum += ways(s, t, i + 1, j);
        return dp[i][j] = sum;
    }

    public int numDistinct(String s, String t) {
        if (s.length() < t.length())
            return 0;
        // no of ways distinct sequence from s = t 
        dp = new int[s.length()][t.length()];
        for (int i = 0; i < s.length(); i++)
            Arrays.fill(dp[i], -1);
        return ways(s.toCharArray(), t.toCharArray(), 0, 0);
    }
}