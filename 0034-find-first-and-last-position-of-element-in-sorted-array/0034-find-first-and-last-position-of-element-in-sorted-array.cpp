typedef vector<int> vi;

class Solution {
private:
    int first_pos(vi& nums, int target) {
        int l = 0, r = size(nums) - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                r = mid - 1;
            } else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return ans;
    }
    int last_pos(vi& nums, int target) {
        int l = 0, r = size(nums) - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                l = mid + 1;
            } else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return ans;
    }

    vi func(vi& nums, int target) {
        int f = first_pos(nums, target);
        int l = last_pos(nums, target);
        return {f, l};
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return func(nums, target);
    }
};