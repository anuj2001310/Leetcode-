bool checkPrimeFrequency(int* nums, int numsSize) {

    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    int freq[101] = {};
    for (int i = 0; i < numsSize; ++i)
        freq[nums[i]]++;

    for (int i = 0; i < 101; ++i) {
        if (freq[i] == 0)
            continue;
        if (isPrime(freq[i]))
            return true;
    }
    return false;
}