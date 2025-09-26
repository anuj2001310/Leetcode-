class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = size(nums);
        sort(begin(nums), end(nums));

        int c = 0;
        for (int i = n - 1; i >= 2; i--) {
            int a = nums[i];
            int k = 0, v = i - 1;
            while (k < v) {
                if (nums[k] + nums[v] > a) {
                    c += (v - k);
                    v--;
                } else {
                    k++;
                }
            }
        }
        return c;
    }
};