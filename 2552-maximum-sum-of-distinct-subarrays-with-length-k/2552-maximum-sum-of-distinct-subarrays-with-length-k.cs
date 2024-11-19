public class Solution {
    public long MaximumSubarraySum(int[] nums, int k) {
        (int head, int tail) = (0,0);

        Span<int> state = stackalloc int[100_001];

        long max = 0;
        long sum = 0;

        while(tail < nums.Length) {
            int n = nums[tail];
            sum += n;
            ++state[n];

            while (head < tail && state[n] > 1)
                AdvanceHead(state);

            if (tail - head + 1 == k) {
                max = Math.Max(max, sum);
                AdvanceHead(state);
            }

            ++tail;
        }

        return max;

        void AdvanceHead(Span<int> state) {
            int n2 = nums[head];
            --state[n2];
            sum -= n2;
            ++head;
        }
    }
}