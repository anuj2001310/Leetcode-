class Solution {
private:
    long long power(int a, int b, int mod = 1000000007) {
        long long res = 1;
        a %= mod;
        while (b != 0) {
            if ((b & 1))
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }
        return res % mod;
    }

public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((n % (i + 1)) == 0)
                sum += (int) (power(nums[i], 2));
        }
        return sum;
    }
};