public class Solution {
    public string FindDifferentBinaryString(string[] nums) {
        var sb = new StringBuilder();
        int n = nums.Length;
        for (int i = 0; i < n; ++i) {
            if (nums[i][i] == '0')
                sb.Append('1');
            else
                sb.Append('0');
        }
        return sb.ToString();
    }
}