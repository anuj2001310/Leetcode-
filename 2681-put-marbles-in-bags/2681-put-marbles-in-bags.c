typedef long long ll;
int cmp(const void* a, const void* b) { 
    return *(int*)a - *(int*)b;
}

long long putMarbles(int* weights, int weightsSize, int k) {
    int* arr = (int*)calloc(sizeof(int), weightsSize - 1);
    for (int i = 0; i < weightsSize - 1; ++i)
        arr[i] += weights[i] + weights[i + 1];
    qsort(arr, weightsSize - 1, sizeof(int), cmp);

    ll ans = 0;
    for (int i = 0; i < k - 1; i++)
        ans += arr[weightsSize - i - 2] - arr[i];

    free(arr);
    return ans;
}