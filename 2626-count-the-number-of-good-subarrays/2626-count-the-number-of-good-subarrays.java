class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        int n = nums.length;
        int left = 0;
        long pairCount = 0;
        long result = 0;

        for (int right = 0; right < n; right++) {
            int val = nums[right];
            int count = freq.getOrDefault(val, 0);
            pairCount += count;
            freq.put(val, count + 1);

            while (pairCount >= k) {
                result += n - right;
                int leftVal = nums[left];
                int leftCount = freq.get(leftVal);
                freq.put(leftVal, leftCount - 1);
                pairCount -= leftCount - 1;
                left++;
            }
        }

        return result;
    }
}