class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();
        if (n < k)
            return false;
        
        int cnt = 0;
        int[] freq = new int[26];
        for (char ch : s.toCharArray())
            freq[ch - 'a']++;
        for (int i = 0; i < 26; i++) {
            if ((freq[i] & 1) != 0)
                cnt++;
        }
        if (cnt > k)
            return false;

        return true;
    }
}