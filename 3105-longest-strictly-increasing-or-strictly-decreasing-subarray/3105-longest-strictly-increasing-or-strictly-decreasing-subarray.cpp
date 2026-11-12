class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n , 1) , dec(n ,1);
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1])
                inc[i] = inc[i -1] + 1;
            if(nums[i] < nums[i -1])
                dec[i] = dec[i -1] + 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans , inc[i]);
            ans = max(ans , dec[i]);
        }
        return ans;
    }
};