class Solution {
public:
    int MOD = 1e9 + 7;
    unordered_map<int, int> primeFactors(int n) {
        unordered_map<int, int> cnts;
        while (n % 2 == 0) {
            cnts[2]++;
            n = n / 2;
        }
        for (int i = 3; i * i <= n; i = i + 2) {
            while (n % i == 0) {
                cnts[i]++;
                n = n / i;
            }
        }
        if (n > 2)
            cnts[n]++;
        return cnts;
    }
    long long mod_pow(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long mod_inv(long long a) { return mod_pow(a, MOD - 2); }

    long long binomial_coefficient(int n, int k) {
        if (k < 0 || k > n)
            return 0;
        if (k == 0 || k == n)
            return 1;

        long long num = 1;
        long long den = 1;

        for (int i = 1; i <= k; i++) {
            num = num * (n - i + 1) % MOD;
            den = den * i % MOD;
        }

        return num * mod_inv(den) % MOD;
    }
    int idealArrays(int n, int maxValue) {
        int ans = 0;
        for (int i = 1; i <= maxValue; i++) {
            unordered_map<int, int> cnts = primeFactors(i);
            long long amt = 1;
            for (pair<int, int> a : cnts) {
                int factor = a.first, cnt = a.second;
                if (cnt == 1) {
                    amt = (amt * n) % MOD;
                    continue;
                }
                long long ncr = binomial_coefficient(n + (cnt - 1), cnt);
                amt = (amt * ncr) % MOD;
            }
            ans = (amt + ans) % MOD;
        }
        return ans;
    }
};