public class Solution {
    public long SumOfLargestPrimes(string s) {
        bool isPrime(long val) {
            if (val == 1)
                return false;
        
            for (int i = 2; i <= (int)Math.Sqrt(val); i++) {
                if (val % i == 0)
                    return false;
            }
        
            return true;
        }

        long ans = 0;
        var n = s.Length;
        var st = new SortedSet<long>();

        for (int i = 0; i < n; ++i) {
            long val = 0;
            for (int j = i; j < n; ++j) {
                val = 10 * val + (s[j] - '0');
                if (isPrime(val))
                    st.Add(val);
            }
        }

        int k = 3;
        while (k-- > 0 && st.Count > 0) {
            long tmp = st.Max;
            st.Remove(tmp);
            ans += tmp;
        }
        return ans;
    }
}