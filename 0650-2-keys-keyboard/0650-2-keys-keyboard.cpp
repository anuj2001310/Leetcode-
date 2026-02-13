class Solution {
public:
    int minSteps(int n) {
       int operations = 0;
    
    // Start from the smallest factor of n, which is greater than 1
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            operations += i;
            n /= i;
        }
    }
    
    return operations; 
    }
};