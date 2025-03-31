public class Solution {
    public long PutMarbles(int[] weights, int k) {
        var n = weights.Length;
        var arr = new int[n - 1];
        for (var i = 0; i < n - 1; ++i)
            arr[i] += weights[i] + weights[i + 1];
        Array.Sort(arr);
        long ans = 0;
        for(int i = 0; i < k - 1; i++)
            ans += arr[n - i - 2] - arr[i];
        
        return ans;
    }
}