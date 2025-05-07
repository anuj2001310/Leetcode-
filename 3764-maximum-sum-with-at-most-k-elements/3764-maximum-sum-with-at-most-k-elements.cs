public class Solution {
    public long MaxSum(int[][] grid, int[] limits, int k) {
        var list = new List<int>();
        foreach (var row in grid)
            Array.Sort<int>(row, new Comparison<int>(
                (i1, i2) => i2.CompareTo(i1)));
        
        for (int i = 0; i < limits.Length; i++) {
            for (int j = 0; j < limits[i]; j++)
                list.Add(grid[i][j]);
        }
        list.Sort((a, b) => b - a);
        long sum = 0;

        for (int i = 0; i < k; i++)
            sum += list[i];
            
        return sum;
    }
}