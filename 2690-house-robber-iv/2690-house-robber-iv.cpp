class Solution {
public:
    bool check(int cap, vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] <= cap) {
                if (--k == 0)
                    return true;

                i += 2;
            }
            else
                i++;
        } 
        return false;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        int low = INT_MAX, high = INT_MIN;
        for (auto& num : nums) {
            low = fmin(low, num);
            high = fmax(high, num);
        }

        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (check(mid, nums, k)) {
                ans = fmin(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};