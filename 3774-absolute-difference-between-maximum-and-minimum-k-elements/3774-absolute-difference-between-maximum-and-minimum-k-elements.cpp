class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        int smaller = 0, larger = 0;
        for (int i = 0; i < k; ++i)
            smaller += nums[i], larger += nums[n - i - 1];

        return larger - smaller;
    }
};