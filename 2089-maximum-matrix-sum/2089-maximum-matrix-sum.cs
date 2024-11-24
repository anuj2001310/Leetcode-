public class Solution {
    public long MaxMatrixSum(int[][] matrix) {
        long sum = 0;
        int cnt = 0, min = Int32.MaxValue;
        foreach (int[] rows in matrix) {
            foreach (int ele in rows) {
                if (ele < 0)
                    cnt++;
                sum += Math.Abs(ele);
                min = Math.Min(min, Math.Abs(ele));
            }
        }
        if ((cnt & 1) != 0)
            return sum - 2 * Math.Abs(min);
        
        return sum;
    }
}