int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

long long countBadPairs(int* a, int b) {
    long long c = (long long)b * (b - 1) / 2, d = 0;
    int* e = (int*)malloc(b * sizeof(int));

    for (int f = 0; f < b; f++)
        e[f] = a[f] - f;

    qsort(e, b, sizeof(int), cmp);

    for (int f = 0, g; f < b; f++) {
        g = f;
        while (g < b && e[g] == e[f])
            g++;
        long long h = g - f;
        d += (h * (h - 1)) / 2;
        f = g - 1;
    }

    free(e);
    return c - d;
}