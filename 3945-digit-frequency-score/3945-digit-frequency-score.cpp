class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum = 0;
        for (; n; n/= 10)
            sum += n % 10;
        return sum;
    }
};