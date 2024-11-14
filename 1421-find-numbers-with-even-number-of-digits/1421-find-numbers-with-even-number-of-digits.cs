public class Solution {
    public int FindNumbers(int[] nums) {
        var cnt = 0;
        foreach (int num in nums) {
            int s = 0;
            int n = num;
            while (n != 0) {
                s++;
                n /= 10;
            } 
            if ((s & 1) == 0)
                cnt++;
        }
        return cnt;
    }
}