class Solution {
    static final int MOD = 1337;

    public int superPow(int a, int[] b) {
        int[] pow = new int[10];
        pow[0] = 1;
        a %= MOD;

        for (int i = 1; i < 10; i++)
            pow[i] = (pow[i - 1] * a) % MOD;
        int n = b.length;
        long ans = pow[b[0]];

        for (int i = 1; i < n; i++)
            ans = (power(ans, 10) * pow[b[i]]) % MOD;

        return (int) ans;
    }

    private long power(long a, int p) {
        long res = 1;
        while (p-- > 0)
            res = (res * a) % MOD;
        return res;
    }
}