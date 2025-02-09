class Solution {
    public long countBadPairs(int[] nums) {
        int n = nums.length;
        long tot = (long)n * (n - 1) / 2;
        long good = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            if (map.containsKey(diff))
                good += (long) map.get(diff);
            map.put(diff, map.getOrDefault(diff, 0) + 1);
        }
        return tot - good;
    }
}