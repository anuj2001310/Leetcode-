public class Solution {
    private bool helper(int[] f, int[] mf) {
        for (int u = 0; u < 26; ++u) {
            if (f[u] < mf[u])
                return false;
        }
        return true;
    }
    public IList<string> WordSubsets(string[] words1, string[] words2) {
        var ans = new List<string>();
        int[] mf = new int[26];
        foreach (var word in words2) {
            int[] f = new int[26];
            foreach (var ch in word)
                f[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                mf[i] = Math.Max(mf[i], f[i]);
        }

        foreach (var word in words1) {
            int[] f = new int[26];
            foreach (var ch in word) 
                f[ch - 'a']++;
            
            if (helper(f, mf))
                ans.Add(word);
        }
        return ans;
    }
}