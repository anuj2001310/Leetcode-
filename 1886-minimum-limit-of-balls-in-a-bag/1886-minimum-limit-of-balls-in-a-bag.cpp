class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxVal = INT_MIN;
        for (auto ele : nums)
            maxVal = max(maxVal, ele);

        int low = 1;
        int high = maxVal;

        while (low <= high) {
            int mid = (high - low) / 2 + low;

            int cnt = 0;

            for (auto ele : nums) {
                cnt += (ele - 1) / mid;
            }

            if (cnt > maxOperations)
                low = mid + 1;
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};