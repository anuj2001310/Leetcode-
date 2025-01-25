import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        List<int[]> help = new ArrayList<>();
        for (int i = 0; i < n; i++)
            help.add(new int[] {nums[i], i});
        
        help.sort((a, b) -> Integer.compare(a[0], b[0]));

        int[] res = new int[n];
        int prev = Integer.MIN_VALUE;
        List<Integer> pos = new ArrayList<>();
        
        for (int s = 0, e = 0; e < n;) {
            pos.add(help.get(e)[1]);
            prev = help.get(e)[0];
            e++;
            if (e == n || help.get(e)[0] - prev > limit) {
                Collections.sort(pos);
                for (int idx : pos) {
                    res[idx] = help.get(s)[0];
                    s++;
                }
                pos.clear();
            }
        }
        return res;
    }
}
