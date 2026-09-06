class Solution {
    const int MOD = 1000000007;
    using ll = long long;
    ll function(ll x, ll y) {
        ll res = 1;
        while (y > 0) {
            if ((y & 1))
                res = (res * x) % MOD;

            x = (x * x) % MOD;
            y >>= 1;
        }

        return res;
    }

public:
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        ll res = 0;

        for (int i = 0; i < n; i++) {
            ll num = nums[i];
            ll width = num % 10;
            ll d1 = num / 10;
            ll t = d1;
            ll dig = 0;
            for (; t > 0; t /= 10)
                dig++;

            ll div = 1;
            for (ll j = 0; j < dig - width; j++)
                div *= 10;

            ll y = d1 % div;
            ll x = d1 / div;

            ll power = function(x, y);

            res = (res + power) % MOD;
        }

        return res;
    }
};