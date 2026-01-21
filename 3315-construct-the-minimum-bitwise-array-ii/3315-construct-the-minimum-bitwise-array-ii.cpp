class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (auto i : nums) {
            if (i == 2) {
                ans.push_back(-1);
            } else {
                int cnt = 0;

                auto j = i;
                while ((j & 1) == 1) {
                    j = j >> 1;
                    cnt++;
                }
                cnt--;
                ans.push_back((i ^ (1 << cnt)));
            }
        }

        return ans;
    }
};