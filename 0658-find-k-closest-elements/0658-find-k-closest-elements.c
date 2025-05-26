/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int l = 0;
    int r = arrSize - 1;
    while (r - l + 1 > k) {
        if (fabs(arr[l] - x) > fabs(arr[r] - x))
            l++;
        else if (fabs(arr[l] - x) <= fabs(arr[r] - x)) 
            r--;
    }

    *returnSize = 0;
    int* result = (int*)calloc(sizeof(int), (r - l + 1));
    
    for (int i = l; i <= r; i++)
        result[(*returnSize)++] = (arr[i]);

    return result;
}