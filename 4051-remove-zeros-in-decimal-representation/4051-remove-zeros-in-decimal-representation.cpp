class Solution {
    using ll = long long;
public:
    long long removeZeros(long long n) {
        ll ans = 0;
        auto num = to_string(n);
        for (auto& ch : num) {
            if (ch == '0')
                continue;
            int id = ch - 48;
            ans = ans * 10 + id;
        }
        return ans;
    }
};