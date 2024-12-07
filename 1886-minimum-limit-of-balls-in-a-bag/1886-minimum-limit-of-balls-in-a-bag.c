
int minimumSize(int* nums, int numsSize, int maxOperations) {
    int i, left, right = 0, mid;

    for (i = 0, left = 0; i < numsSize; i++)
        if (left < nums[i])
            left = nums[i];

    while (left > right) {
        mid = (left + right) / 2 + (left + right) % 2;

        long long count = 0;

        for (i = 0; i < numsSize; i++)
            count += nums[i] / mid - 1 + (nums[i] % mid > 0);

        if (count > maxOperations)
            right = mid;
        else
            left = mid - 1;
    }

    return left + 1;
}