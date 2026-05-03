class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = size(nums);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int mask = (nums[i] & 1);
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if ((nums[j] & 1) == mask)
                    continue;
                cnt++;
            }

            ans[i] = cnt;
        }
        return ans;
    }
};