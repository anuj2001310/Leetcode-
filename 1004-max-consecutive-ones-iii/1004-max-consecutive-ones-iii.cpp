class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, zero = 0, ans = -1;
        for (; r < n; r++) {
            if (nums[r] == 0)
                zero++;
            
            while (zero > k)
                if (nums[l++] == 0)
                    zero--;
            ans = fmax(ans, r - l + 1);
        }
        return ans;
    }
};