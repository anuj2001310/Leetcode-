int smallestIndex(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        int num = nums[i];
        while (num) {
            sum += num % 10;
            if (sum > i)
                break;
            num /= 10;
        }
        if (sum == i)
            return i;
    }
    return -1;
}