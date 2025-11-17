class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec;
        for (int i = 0; i < n; ++i)
            if (nums[i])
                vec.push_back(i);
        for (int i = 0; i + 1 < size(vec); ++i) {
            if (vec[i + 1] - vec[i] <= k)
                return false;
        }
        return true;
    }
};