class Solution {
    private boolean helper(int[] f, int[] mf) {
        for (int u = 0; u < 26; ++u) {
            if (f[u] < mf[u])
                return false;
        }
        return true;
    }
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> ans = new ArrayList<>();
        int[] mf = new int[26];
        for (String word : words2) {
            int[] f = new int[26];
            for (char ch : word.toCharArray())
                f[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                mf[i] = Math.max(mf[i], f[i]);
        }

        for (String word : words1) {
            int[] f = new int[26];
            for (char ch : word.toCharArray()) 
                f[ch - 'a']++;
            
            if (helper(f, mf))
                ans.add(word);
        }
        return ans;
    }
}