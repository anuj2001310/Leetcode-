class Solution {
    public int findClosest(int x, int y, int z) {
        int d1 = Math.abs(x - z);
        int d2 = Math.abs(y - z);

        return (d1 >= d2) ? ((d1 == d2) ? 0 : 2) : 1;
    }
}