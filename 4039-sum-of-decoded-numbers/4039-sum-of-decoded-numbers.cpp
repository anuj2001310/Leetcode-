class Solution {
using ll = long long;
const int MOD = 1000000007;
public:
    ll expo (ll x, ll y) {
        ll res = 1;
        while (y > 0) {
            if ((y & 1))
                res = (res * x) % MOD;
            
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            ll num = nums[i];
            int w = num % 10;
            ll d = num / 10;
            ll t = d;
            int dig = 0;

            while (t > 0) {
                dig++;
                t /= 10;
            }

            ll div = 1;
            int rem = dig - w;

            while (rem--)
                div *= 10;
            
            ll y = d % div;
            ll x = d / div;
            ll power = expo(x, y);

            res = (res + power) % MOD;
        }
        return res;
    }
};