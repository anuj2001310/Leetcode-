class Solution {
    public int majorityElement(int[] nums) {
        int m = Integer.MAX_VALUE, c = 0;
        for (int num : nums) {
            if (c == 0) {
                c = 1;
                m = num;
            } else if (m == num)
                c++;
            else
                c--;
        }
        return m;
    }
}