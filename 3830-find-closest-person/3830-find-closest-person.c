int findClosest(int x, int y, int z) {
    return (fabs(x - z) >= fabs(y - z)) ? ((fabs(x - z) == fabs(y - z)) ? 0 : 2) : 1;
}