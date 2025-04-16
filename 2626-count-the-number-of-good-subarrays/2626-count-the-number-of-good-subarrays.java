class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        int n = nums.length;
        int l = 0;
        long pairCount = 0;
        long result = 0;

        for (int r = 0; r < n; r++) {
            int val = nums[r];
            int count = freq.getOrDefault(val, 0);
            pairCount += count;
            freq.put(val, count + 1);

            while (pairCount >= k) {
                result += n - r;
                int leftVal = nums[l];
                int leftCount = freq.get(leftVal);
                freq.put(leftVal, leftCount - 1);
                pairCount -= leftCount - 1;
                l++;
            }
        }

        return result;
    }
}