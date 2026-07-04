bool isMiddleElementUnique(int* nums, int n) {
    int mid = nums[n >> 1];
    int ct = 0, i = 0;
    for (; i < n; i++) {
        if (nums[i] == mid)
            ct++;
    }
    return ct == 1;
}