int cmp(const void* a, const void* b) { 
    return *(int*)a - *(int*)b;
}

int maxIceCream(int* costs, int costsSize, int coins) {
    int ct = 0;
    qsort(costs, costsSize, sizeof(int), cmp);
    for (int i = 0; i < costsSize; ++i) {
        int diff = coins - costs[i];
        if (diff < 0)
            break;
        coins -= costs[i];
        ct++;
    }
    return ct;
}