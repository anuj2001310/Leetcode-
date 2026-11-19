int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimizeSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int opt1 = nums[numsSize - 1] - nums[2];
    int opt2 = nums[numsSize - 2] - nums[1];
    int opt3 = nums[numsSize - 3] - nums[0];
    
    int min_val = opt1 < opt2 ? opt1 : opt2;
    return min_val < opt3 ? min_val : opt3;
}