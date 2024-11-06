int count(int n) {
    int bit = 0;
    while (n) {
        bit++;
        n = n & (n - 1);
    }
    return bit;
}
bool canSortArray(int* nums, int numsSize) {
    int l = 0, h = nums[0];
    bool bit;
    for (int i = 1; i < numsSize; ++i) {
        bit = (count(h) != count(nums[i]));
        if (bit)
            l = h;
        if (nums[i] > h)
            h = nums[i];
        if (nums[i] < l)
            return false;
    }
    return true;
}