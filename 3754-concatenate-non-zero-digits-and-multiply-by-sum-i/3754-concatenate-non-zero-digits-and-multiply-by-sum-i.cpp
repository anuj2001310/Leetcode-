class Solution {
public:
    long long sumAndMultiply(int n) {
        using ll = long long;
        ll ans = 0;
        int sum = 0;
        for (auto& ch : to_string(n)) {
            if (ch == '0')
                continue;
            
            sum += (ch - '0');
            ans = 10 * ans + (ch - 48);
        }
        return ans * sum;
    }
};