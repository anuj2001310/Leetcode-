public class Solution {
    public int MinDeletion(string s, int k) {
        var freq = new int[26];
        var dis = 0;
        
        foreach (var ch in s) {
            int idx = ch - 'a';
            if (freq[idx] == 0)
                dis++;
            freq[idx]++;
        }
        
        if (k >= dis)
            return 0;
        
        Array.Sort(freq);
        int del = 0;
        
        for (int i = 0, j = 0; i < 26 && j < dis - k; i++) {
            if (freq[i] != 0) {
                del += freq[i];
                j++;
            }
        }

        return del;
    }
}