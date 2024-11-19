long long maximumSubarraySum(int* nums, int numsSize, int k) {
    if (numsSize < k)
        return 0;

    long long result = 0;
    long long current = 0;
    int index = 0;
    int storage[100001] = {0};

    for (int i = 0; i < numsSize; i++) {
        while (storage[nums[i]] == 1) {
            storage[nums[index]] = 0;
            current = current - nums[index];
            index++;
        }

        storage[nums[i]] = 1;
        current = current + nums[i];

        if (i - index + 1 == k) {
            if (result < current)
                result = current;

            current = current - nums[index];
            storage[nums[index]] = 0;
            index++;
        }
    }

    return result;
}