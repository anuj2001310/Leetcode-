public class Solution {
    public long CountBadPairs(int[] nums) {
        var n = nums.Length;
        var map = new Dictionary<long, long>();
        for (long i = 0; i < n; i++) {
            long dif = nums[i] - i;
            if (map.ContainsKey(dif))
                map[dif]++;
            else
                map[dif] = 1;
        }
        long tot = (long )n * (n - 1) / 2;
        long good = 0;
        foreach(var item in map) {
            var val = item.Value;
            if (val > 0)
                good += val * (val - 1) / 2;
        }
        return tot - good;
    }
}