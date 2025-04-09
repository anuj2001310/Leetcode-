int minOperations(int* nums, int numsSize, int k) {
    int arr[101] = {};
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < k)
            return -1;
        else if (nums[i] > k)
            arr[nums[i]]++;
    }
    uint cnt = 0;
    for (int i = 0; i < 101; ++i)
        if (arr[i])
            cnt++;
    return cnt;
}