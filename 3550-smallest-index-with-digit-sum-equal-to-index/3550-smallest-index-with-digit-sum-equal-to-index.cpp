class Solution {
private:
    int sum(int num) { return ((num == 0) ? 0 : num % 10 + sum(num / 10)); }

public:
    int smallestIndex(vector<int>& nums) {
        int n = size(nums);
        for (int u = 0; u < n; u++) {
            if (u == sum(nums[u]))
                return u;
        }
        return -1;
    }
};