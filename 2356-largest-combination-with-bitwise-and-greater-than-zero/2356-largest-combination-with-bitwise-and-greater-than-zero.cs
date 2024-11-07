public class Solution {
    public int LargestCombination(int[] candidates) {
        int[] arr = new int[32];
        int ans = 0;
        void bitCount(int n) {
            for (int i = 0; i < 32; ++i) {
                int mask = 1 << i;
                if ((mask & n) != 0)
                    arr[i]++;
                ans = Math.Max(ans, arr[i]);
            }
        }

        foreach(var ele in candidates)
            bitCount(ele);
        
        return ans;
    }
}