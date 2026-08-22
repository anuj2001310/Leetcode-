class Solution {
    private int digitSum(int num) {
        if (num == 0)
            return 0;
        return (num % 10) + digitSum(num / 10);
    }

    private int digitProduct(int num) {
        if (num == 0)
            return 1;

        return (num % 10) * digitProduct(num / 10);
    }

    public boolean checkDivisibility(int n) {
        return (n % (digitSum(n) + digitProduct(n)) == 0);
    }
}