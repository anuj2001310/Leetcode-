/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);

    int* res = (int*)calloc(sizeof(int), n);
    int b = 0, m = 0;
    for (int i = 0; i < n; i++) {
        res[i] = (b + m);
        m += b;
        b += (boxes[i] - '0');
    }

    b = m = 0;
    for (int i = n - 1; i >= 0; i--) {
        res[i] += (b + m);
        m += b;
        b += (boxes[i] - '0');
    }
    *returnSize = n;
    return res;
}