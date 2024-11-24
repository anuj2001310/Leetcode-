class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int cnt = 0, min = Integer.MAX_VALUE;
        long sum = 0;
        for (int[] row : matrix) {
            for (int ele : row) {
                if (ele < 0)
                    cnt++;
                sum += Math.abs(ele);
                min = Math.min(min, Math.abs(ele));
            }
        }
        if ((cnt & 1) != 0)
            return sum - 2 * Math.abs(min);
        return sum;
    }
}