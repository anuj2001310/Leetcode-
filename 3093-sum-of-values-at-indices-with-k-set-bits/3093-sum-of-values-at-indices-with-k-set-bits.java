class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < 32; ++j) {
                int mask = (1 << j);
                if ((mask & i) != 0)
                    cnt++;
            }
            if (cnt == k)
                sum += nums.get(i);
        }
        return sum;
    }
}