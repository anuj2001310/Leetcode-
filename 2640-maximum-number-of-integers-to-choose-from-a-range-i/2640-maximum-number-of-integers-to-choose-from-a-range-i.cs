public class Solution {
    public int MaxCount(int[] banned, int n, int maxSum) {
        bool[] hash = new bool[10001];
        foreach (int num in banned)
            hash[num] = true;
        
        var sum = 0;
        var cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!hash[i]) {
                sum += i;
                if (sum <= maxSum)
                    cnt++;
                else
                    return cnt;
            }
            else
                continue;
        }
        return cnt;
    }
}