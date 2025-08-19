class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        long long temp = 0, maxcount = 0;

        bool flag = false;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                temp++;
            else {
                maxcount = temp;
                temp = 0;
                flag = true;
            }
            
            if (flag) {
                res = res + (maxcount * (maxcount + 1) / 2);
                flag = false;
            }
        }
        if (temp)
            res += (temp * (temp + 1) / 2);

        return res;
    }
};