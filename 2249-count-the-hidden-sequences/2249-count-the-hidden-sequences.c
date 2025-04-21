int numberOfArrays(int* differences, int n, int lower, int upper) {
    int cur = 0, min = 0, max = 0;
    for (int i = 0; i < n; i++) {
        cur += differences[i];
        min = (min < cur) ? min : cur;
        max = (max > cur) ? max : cur;

        if ((upper - max) - (lower - min) + 1 <= 0)
            return 0;
    }
    return (upper - max) - (lower - min) + 1; 
}