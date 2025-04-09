public class Solution {
    public int MinOperations(int[] nums, int k) {
        var map = new int[101];
        foreach (var num in nums)
            if (num < k)
                return -1;
            else if (num > k)
                map[num]++;
        
        int cnt = 0;
        for (int i = 0; i < 101; ++i)
            if (map[i] != 0)
                cnt++;
        
        return cnt;
    }
}