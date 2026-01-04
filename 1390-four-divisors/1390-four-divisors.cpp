constexpr int MX = 100'001;
int divisor_num[MX];
int divisor_sum[MX];

int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) { // 枚举 i 的倍数 j
            divisor_num[j]++; // i 是 j 的因子
            divisor_sum[j] += i;
        }
    }
    return 0;
}();

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            if (divisor_num[x] == 4) {
                ans += divisor_sum[x];
            }
        }
        return ans;
    }
};