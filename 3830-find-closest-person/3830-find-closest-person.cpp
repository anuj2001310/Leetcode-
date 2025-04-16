class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = fabs(x - z), d2 = fabs(y - z);
        return (d1 >= d2) ? ((d1 == d2) ? 0 : 2) : 1;
    }
};