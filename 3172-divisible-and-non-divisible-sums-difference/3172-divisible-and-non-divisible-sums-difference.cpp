class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        int divisibleSum_times_2 = m * k * (k + 1);
        int totalSum = (n * (n + 1)) >> 1;
        return totalSum - divisibleSum_times_2;
    }
};