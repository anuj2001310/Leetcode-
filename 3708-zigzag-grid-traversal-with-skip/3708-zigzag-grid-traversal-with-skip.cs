public class Solution {
    public IList<int> ZigzagTraversal(int[][] grid) {
        var ans = new List<int>();
        var cnt = 0;
        var n = grid.Length; 
        for (var i = 0; i < n; i++) {
            if ((i & 1) != 0) {
                for (var j = grid[i].Length - 1; j >= 0; j--) {
                    if ((cnt & 1) == 0)
                        ans.Add(grid[i][j]);
                    cnt++;
                }
            } else {
                for (var j = 0; j < grid[i].Length; j++) {
                    if ((cnt & 1) == 0)
                        ans.Add(grid[i][j]);
                    cnt++;
                }
            }
        }
        return ans;
    }
}