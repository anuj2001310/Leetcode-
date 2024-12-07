public class Solution {
    public int MinimumSize(int[] nums, int maxOperations) {
        int l = 1, r = nums.Max();

        while (l < r) {
            int m = l + (r - l) / 2, c = 0;
            foreach (int a in nums)
                 c += (a - 1) / m;
            if (c > maxOperations)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
}