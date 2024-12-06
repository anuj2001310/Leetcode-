class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        boolean[] hash = new boolean[10001];
        for (int x : banned)
            hash[x] = true;

        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!hash[i]) {
                sum += i;
                if (sum <= maxSum)
                    cnt++;
                else
                    return cnt;
            } else
                continue;
        }
        return cnt;
    }
}