public class Solution {
    public bool IsZeroArray(int[] nums, int[][] queries) {
        int n = nums.Length;
        int[] del = new int[n + 1];
        
        foreach (int[] q in queries) {
            int l = q[0];
            int r = q[1];
            del[l]++;
            del[r + 1]--;
        }
        
        for (int i = 1; i <= n; ++i)
            del[i] += del[i - 1];
        for (int i = 0; i < n; ++i) {
            if (del[i] < nums[i])
                return false;
        }
        return true;
    }
}