#define INF std::numeric_limits<int>::max()
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstMax = -INF;
        int secondMax = -INF;
        int thirdMax = -INF;

        int firstMin = INF;
        int secondMin = INF;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            } else if (nums[i] >= secondMax) {
                thirdMax = secondMax;
                secondMax = nums[i];
            } else if (nums[i] > thirdMax)
                thirdMax = nums[i];
            if (nums[i] <= firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }
        int a = firstMax * secondMax * thirdMax;
        int b = firstMax * firstMin * secondMin;
        return max(a, b);
    }
};