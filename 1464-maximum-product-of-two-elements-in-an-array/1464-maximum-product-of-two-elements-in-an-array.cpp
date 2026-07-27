class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int f =  std::numeric_limits<int>::min();
        int s = f;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= f) {
                s = f;
                f = nums[i];
            } else if (nums[i] < f and nums[i] > s)
                s = nums[i];
        }
        return (f - 1) * (s - 1);
    }
};