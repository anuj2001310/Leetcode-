int findNumbers(int* nums, int numsSize) {
    int cnt = 0;
    for (int i = 0; i < numsSize; ++i) {
        int size = 0;
        while (nums[i]) {
            size++;
            nums[i] /= 10;
        }
        if (!(size & 1))
            cnt++;
    }
    return cnt;
}