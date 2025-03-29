typedef long long ll;

class Solution {
    const int MOD = 1e9 + 7;

private:
    long long power(ll base, ll exponent) {
        ll res = 1;

        while (exponent > 0) {
            if ((exponent & 1))
                res = ((res * base) % MOD);

            base = (base * base) % MOD;
            exponent >>= 1;
        }

        return res;
    }

    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int n = 2; n <= limit; n++) {
            if (!isPrime[n])
                continue;

            primes.push_back(n);

            for (ll multiple = (ll)n * n; multiple <= limit; multiple += n) {
                isPrime[multiple] = false;
            }
        }

        return primes;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> primes = getPrimes(maxElement);

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (auto& prime : primes) {
                if (prime * prime > num)
                    break;
                if (num % prime != 0)
                    continue;

                primeScores[i]++;
                while (num % prime == 0)
                    num /= prime;
            }
            if (num > 1)
                primeScores[i]++;
        }

        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        stack<int> dec;
        for (int i = 0; i < n; i++) {
            while (!dec.empty() && primeScores[dec.top()] < primeScores[i]) {
                int topIndex = dec.top();
                dec.pop();

                nextDominant[topIndex] = i;
            }
            if (!dec.empty())
                prevDominant[i] = dec.top();

            dec.push(i);
        }
        vector<long long> numOfSubarrays(n);
        for (int i = 0; i < n; i++)
            numOfSubarrays[i] =
                (ll)(nextDominant[i] - i) * (i - prevDominant[i]);

        vector<pair<int, int>> sortedArray(n);
        for (int idx = 0; idx < n; idx++)
            sortedArray[idx] = {nums[idx], idx};

        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        ll score = 1;
        int pid = 0;
        while (k > 0) {
            auto& [num, index] = sortedArray[pid++];

            ll operations = min((ll)k, numOfSubarrays[index]);

            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }

        return score;
    }
};