class Solution {
public:
    long long minEnd(unsigned n, unsigned x) {
        bitset<64> X(x), N(n - 1), ans = 0;
        int sz = 64 - countl_zero(x) - countl_zero(n - 1);
        for (int i = 0, j = 0; i < sz; i++) {
            ans[i] = (X[i]) ? 1 : N[j++];
        }
        return ans.to_ullong();
    }
};