class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if (a == b and b == c)
            return "equilateral";
        if ((a == b and a + b > c) || (b == c and b + c > a) or
            (a == c and a + c > b))
            return "isosceles";
        if (a + b > c and b + c > a and a + c > b)
            return "scalene";

        return "none";
    }
};