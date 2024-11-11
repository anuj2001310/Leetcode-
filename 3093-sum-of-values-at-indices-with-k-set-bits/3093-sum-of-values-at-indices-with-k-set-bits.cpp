class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < 32; ++j) {
                int mask = (1 << j);
                if (i & mask)
                    cnt++;
            }
            if (cnt == k)
                sum += nums[i];
        }
        return sum;
    }
};