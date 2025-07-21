int sumOfUnique(int* nums, int numsSize) {
    int arr[101] = {0};
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        arr[nums[i]]++;
    for (int i = 1; i < 101; i++) //We start loop from 1 because there is no 0 in given constraints so need to visit index 0
        if (arr[i] == 1)
            sum += i;

    return sum;
}