public class Solution {
    public int CountLargestGroup(int n) {
        var sums = new int[37];

        int sumOfDig(int num) {
            return (num == 0 ? 0 : (num % 10) + sumOfDig(num / 10));
        }

        for (int i = 1; i <= n; ++i)
            sums[sumOfDig(i)]++;

        int ans = 0, max = 0;

        for (int i = 0; i < 37; i++)
            if (sums[i] > max) {
                max = sums[i]; 
                ans = 1;
            }
            else if (sums[i] == max)
                ++ans;        
        return ans;
    }
}