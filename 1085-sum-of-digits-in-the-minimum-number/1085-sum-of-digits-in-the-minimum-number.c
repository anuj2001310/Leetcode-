int sumOfDigits(int* nums, int numsSize) {
    int min = INT_MAX;
    for (int i = 0; i < numsSize; ++i)
        min = fmin(min, *(nums + i));

    int sum = 0;
    while (min) {
        sum += min % 10;
        min /= 10;
    }
    
    return ((sum & 1) != 0 ? 0 : 1);
}