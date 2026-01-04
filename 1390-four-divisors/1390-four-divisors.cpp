class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // This will store the final answer
        int totalSum = 0;

        // Iterate through each number in the array
        for (int x : nums) {
            int count = 0; // counts how many divisors x has
            int sum = 0;   // stores sum of divisors of x

            // Check every number from 1 to x
            for (int d = 1; d <= x; d++) {
                // If d divides x, then d is a divisor
                if (x % d == 0) {
                    count++;   // increase divisor count
                    sum += d;  // add divisor to sum
                }
            }

            // Only add the sum if x has exactly 4 divisors
            if (count == 4) {
                totalSum += sum;
            }
        }

        // Return the final sum
        return totalSum;
    }
};