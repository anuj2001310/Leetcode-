public class Solution {
    const int MOD = 1000000007;

    public int[] BaseUnitConversions(int[][] conversions) {
        var adj = new List<List<(int, long)>>();
        int n = conversions.Length + 1;
         for (int i = 0; i < n; i++) {
               adj.Add(new List<(int, long)>());
        }

        foreach (var conv in conversions){
            int s = conv[0];
            int t = conv[1];
            long k = conv[2]; 
            long inK = Pow(k, MOD - 2, MOD);  
                adj[s].Add((t, k % MOD));
                adj[t].Add((s, inK));
            }

            long[] rt = new long[n];
            rt[0] = 1;
            var q = new Queue<int>();
            q.Enqueue(0);

            while (q.Count > 0) {
                int u = q.Dequeue();
                foreach (var tuple in adj[u]) {
                    int v = tuple.Item1;
                    long k = tuple.Item2;
                    if (rt[v] == 0) {
                        rt[v] = (rt[u] * k) % MOD;
                        q.Enqueue(v);
                    }
                }
            }

            int[] result = new int[n];
            for (int i = 0; i < n; i++) 
               result[i] = (int)(rt[i] % MOD);
        
            return result;
        }
    private long Pow(long a, int exponent, int mod) {
        long result = 1;
        a %= mod;
        while (exponent > 0) {
            if ((exponent & 1) != 0)
                   result = (result * a) % mod;
               
            a = (a * a) % mod;
            exponent >>= 1;
        }
        return result;
    }
}