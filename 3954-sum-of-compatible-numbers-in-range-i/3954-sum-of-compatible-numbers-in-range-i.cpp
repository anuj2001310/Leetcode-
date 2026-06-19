class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for (int i = max(1, n - k); ; i++) {
            if (i > n + k)
                break;
            if ((i & n) == 0)
                sum += i;
        }
        return sum;
    }
};