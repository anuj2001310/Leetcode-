class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 1, maxi = 1, sum = nums[0];

        while (right < n) {
            while ((sum & nums[right]) != 0)
                sum ^= nums[left++];
            sum |= nums[right];
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};