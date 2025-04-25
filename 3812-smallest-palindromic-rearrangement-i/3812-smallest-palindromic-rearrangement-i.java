class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();
        if (n == 1)
            return s;
        var freq = new int[26];
        for (char ch : s.toCharArray()) {
            int idx = ch - 'a';
            freq[idx]++;
        }
        int min_idx = -1;
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < freq[i] / 2; ++j)
                sb.append((char) (i + 'a'));
            if (freq[i] % 2 != 0)
                if (min_idx == -1)
                    min_idx = i;
        }
        String first = sb.toString();
        String last = new StringBuilder(sb).reverse().toString();
       
        if (min_idx == -1)
            return first + sb.reverse().toString();
        sb.append((char) (min_idx + 'a'));
        return sb.toString() + last;
    }
}