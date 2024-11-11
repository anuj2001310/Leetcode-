class Solution {
    static int bits(int n) {
        int bit = 0;
        while (n != 0) {
            n = n & (n - 1);
            bit++;
        }
        return bit;
    }

    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (bits(i) == k)
                sum += nums.get(i);
        }
        return sum;
    }
}