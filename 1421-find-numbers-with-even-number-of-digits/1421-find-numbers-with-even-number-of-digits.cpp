class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int size = 0;
            while (num) {
                size++;
                num /= 10;
            }
            if (!(size & 1))
                cnt++;
        }
        return cnt;
    }
};