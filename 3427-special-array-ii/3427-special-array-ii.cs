public class Solution {
    public bool[] IsArraySpecial(int[] nums, int[][] queries) {
        int n = nums.Length;
        int q = queries.Length;
        int[] hell = new int[n];
        for (var i = 1; i < n; ++i)
            hell[i] = (((nums[i] ^ nums[i - 1]) & 1) != 0) ? hell[i - 1] : i;
        
        bool[] ans = new bool[q];
        for (int i = 0; i < q; ++i) {
            int f =  queries[i][0];
            int t =  queries[i][1];
            ans[i] = hell[t] <= f;
        }
        return ans;
    }
}