class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder sb = new StringBuilder();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i].charAt(i) == '0')
                sb.append('1');
            else
                sb.append('0');
        }
        return sb.toString();
    }
}