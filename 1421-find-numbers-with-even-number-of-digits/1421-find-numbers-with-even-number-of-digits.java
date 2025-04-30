class Solution {
    public int findNumbers(int[] nums) {
        int cnt = 0;
        for (int num : nums) {
            int size = 0;
            while (num != 0) {
                size++;
                num /= 10;
            }
            if ((size & 1) == 0)
                cnt++;
        }
        return cnt;
    }
}