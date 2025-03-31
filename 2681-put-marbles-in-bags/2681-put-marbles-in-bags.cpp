using ll = long long;
using head = int;
#define v.begin(), v.end() all(v)

class Solution {
public:
    ll putMarbles(vector<int>& weights, int k) {
        head n = weights.size();
        vector<head> p(n - 1, 0);
        for (head i = 0; i < n - 1; ++i)
            p[i] += weights[i] + weights[i + 1];

        sort(p.begin(), p.end());

        ll ans = 0;
        for (head i = 0; i < k - 1; ++i)
            ans += p[n - 2 - i] - p[i];

        return ans;
    }
};