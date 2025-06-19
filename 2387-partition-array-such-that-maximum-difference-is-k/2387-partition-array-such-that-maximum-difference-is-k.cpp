class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int min_val = std::numeric_limits<int>::max(), max_val = std::numeric_limits<int>::min();
        int cnt = 1;
        ranges::sort(nums);

        for (int i = 0; i < n; ++i) {
            min_val = fmin(min_val, nums[i]);
            max_val = fmax(max_val, nums[i]);
            if (max_val - min_val > k) {
                cnt++;
                min_val = nums[i];
            }
        }
        return cnt;
    }
};