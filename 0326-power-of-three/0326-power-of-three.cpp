class Solution {
public:
    bool isPowerOfThree(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (n < 1)
            return false;

        if (n == 1)
            return true;
        bool ans = n % 3 == 0 && isPowerOfThree(n / 3);
        return ans;
    }
};