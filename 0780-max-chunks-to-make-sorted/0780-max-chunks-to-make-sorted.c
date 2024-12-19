int maxChunksToSorted(int* arr, int arrSize) {
    int c = 0, m = -1;
    for (uint u = 0; u < arrSize; ++u) {
        m = fmax(m, arr[u]);
        if (m == u)
            ++c;
    }
    return c;
}