class Solution {
    public int largestPrime(int n) {
        if (n < 2)
            return 0;

        boolean[] p = new boolean[n + 1];
        Arrays.fill(p, true);
        p[0] = false;
        p[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (p[i]) {
                for (int j = i * i; j <= n; j += i) {
                    p[j] = false;
                }
            }
        }

        int s = 0;
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (p[i]) {
                s += i;
                if (s > n)
                    break;
                if (p[s])
                    ans = s;
            }
        }

        return ans;
    }
}