class Solution {
    static int sum_of_digits(int num) {
        if (num == 0)
            return 0;
        return num % 10 + sum_of_digits(num / 10);
    }

    public int countLargestGroup(int n) {
        var sums = new int[37];

        for (int i = 1; i <= n; i++)
            sums[sum_of_digits(i)]++;
        int max = 0, cnt = 0;
        
        for (int i = 0; i < sums.length; i++) {
            if (sums[i] > max) {
                max = sums[i];
                cnt = 1;
            } else if (sums[i] == max)
                cnt++;
        }
        return cnt;
    }
}