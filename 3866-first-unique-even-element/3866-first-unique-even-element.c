int firstUniqueEven(int* nums, int n) {

    int map[101] = {};

    for (int i = 0; i < n; i++)
        map[nums[i]]++;
        
    for (int i = 0; i < n; ++i) {
        if ((nums[i] & 1) == 0 && map[nums[i]] == 1)
            return nums[i];
    }
    return -1;
}