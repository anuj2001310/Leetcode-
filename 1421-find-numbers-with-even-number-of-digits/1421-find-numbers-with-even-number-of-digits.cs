public class Solution {
    public int FindNumbers(int[] nums) {
        var cnt = 0;
        foreach (var n in nums) {
            int num = n;
            int size = 0;
            while (num != 0) {
                num /= 10;
                size++;
            }
            if ((size & 1) == 0)
                cnt++;
        }
        return cnt;
    }
}