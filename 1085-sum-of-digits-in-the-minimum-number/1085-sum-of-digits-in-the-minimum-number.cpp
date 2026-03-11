class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int min = std::numeric_limits<int>::max();
        int n = size(nums);
        for (int i = 0; i < n; ++i)
            min = fmin(min, nums[i]);
        
        int sum = 0;
        while (min) {
            sum += min % 10;
            min /= 10;
        }
        return ((sum & 1) != 0 ? 0 : 1);
    }
};