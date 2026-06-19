int largestAltitude(int* gain, int gainSize) {
    int sum = 0;
    int max_1 = 0;
    for (int i = 0; i < gainSize; i++) {
        sum = sum + gain[i];
        max_1 = fmax(max_1, sum);
    }
    return max_1;
}