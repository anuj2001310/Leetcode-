class Solution {
public:
    int totalMoney(int n) {
        int x = n / 7;
        return (7 * (7 + 1) / 2) * x + ((x - 1) * x / 2) * 7 +
               ((n % 7) * (n % 7 + 1) / 2) + (n % 7) * x;
    }
};