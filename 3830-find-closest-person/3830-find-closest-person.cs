public class Solution {
    public int FindClosest(int x, int y, int z) {
        return (Math.Abs(x - z) >= Math.Abs(y - z)) ? ((Math.Abs(x - z) == Math.Abs(y - z)) ? 0 : 2) : 1;
    }
}