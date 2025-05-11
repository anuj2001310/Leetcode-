class Solution {
    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    public int maxFreqSum(String s) {
        int n = s.length();
        var freq = new int[26];
        int v = 0, c = 0;
        for (char ch : s.toCharArray())
            freq[ch - 'a']++;
        for (int i = 0; i < n; ++i) {
            char ch = s.charAt(i);
            int idx = ch - 'a';
            if (isVowel(ch))
                v = (freq[idx] > v ? freq[idx] : v);
            else
                c = (freq[idx] > c ? freq[idx] : c);
        }
        return v + c;
    }
}