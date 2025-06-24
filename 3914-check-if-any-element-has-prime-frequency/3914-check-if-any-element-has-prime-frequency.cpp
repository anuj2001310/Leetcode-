class Solution {
private:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        array<int, 101> map;

        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }

        for (int i = 0; i < 101; i++) {
            if (map[i] == 0)
                continue;
            if (isPrime(map[i]))
                return true;
        }
        return false;
    }
};