class Solution {
public:
    bool completePrime(int num) {
        function<bool(int)> isPrime = [&](int num) {
            if (num <= 1)
                return false;
            
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0)
                    return false;
            }
            return true;
        };
        int suffix = 0, prefix = 1, help = num;
        while (help) {
            suffix = prefix * (help % 10) + suffix;
            if (suffix == 1 || isPrime(suffix) == false)
                return false;

            if (help == 1 || isPrime(help) == false)
                return false;

            prefix *= 10;
            help /= 10;
        }
        return true;
    }
};