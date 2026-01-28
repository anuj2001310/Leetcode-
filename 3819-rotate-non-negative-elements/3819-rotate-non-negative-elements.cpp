class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = size(nums), m = 0;
        vector<int> a(n, 0);

        for (auto& num : nums) {
            if (num >= 0)
                a[m++] = num;
        }
        if (m == 0)
            return nums;
        k %= m;
        for (int i = 0, j = 0; i < n; i++) {
            if (nums[i] >= 0)
                nums[i] = a[(j++ + k) % m];
        }
        return nums;
    }
};