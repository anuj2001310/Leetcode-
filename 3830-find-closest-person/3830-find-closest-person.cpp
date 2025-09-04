class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = fabs(x - z), b = fabs(y - z);
        return (a == b) ? 0 : (a < b ? 1 : 2);
    }
};