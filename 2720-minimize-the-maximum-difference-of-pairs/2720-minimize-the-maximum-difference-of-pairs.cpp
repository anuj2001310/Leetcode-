class Solution {
private:
    int countValid(vector<int>& nums, int threshold) {
        int idx = 0, count = 0;

        while (idx < nums.size() - 1) {
            if (nums[idx + 1] - nums[idx] <= threshold) {
                count++;
                idx++;
            }
            idx++;
        }

        return count;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0];

        while (l < r) {
            int m = (l + (r - l) / 2);
            if (countValid(nums, m) >= p)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};