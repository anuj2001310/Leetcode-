class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int x : nums) {
            int num = x;
            int size = 0;
            while (num != 0) {
                size++;
                num /= 10;
            }
            if ((size & 1) == 0)
                count++;
        }
        return count;
    }
}