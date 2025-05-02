public class Solution {
    public bool[] PathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int q = queries.Length;
        var cnt = 0;
        var comp = new int[n];
        for (var i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                comp[i] = cnt;
            else
                comp[i] = ++cnt;
        }
        var ans = new bool[q];
        for (var i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = (comp[u] == comp[v]);
        }
        return ans;
    }
}