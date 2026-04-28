class Solution {
public:
    bool validDigit(int n, int x) {
        bool flag = false;
        int dig;
        while (n) {
            int r = n % 10;
            if (r == x)
                flag = true;
            n /= 10;
            dig = r;
        }

        return (flag && (dig != x));
    }
};