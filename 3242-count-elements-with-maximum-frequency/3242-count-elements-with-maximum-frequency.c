int maxFrequencyElements(int* nums, int numsSize) {
    int freq[101] = {};
    int max = INT_MIN;
    for (int r = 0; r < numsSize; ++r) {
        freq[nums[r]]++;
        max = fmax(max, freq[nums[r]]);
    }
    int cnt = 0;
    for (int i = 0; i < 101; ++i) {
        if (freq[i] == 0)
            continue;
        cnt += (freq[i] == max);
    }

    return cnt * max;
}