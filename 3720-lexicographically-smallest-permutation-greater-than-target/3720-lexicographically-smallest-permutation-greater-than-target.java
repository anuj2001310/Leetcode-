class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        StringBuilder prefix = new StringBuilder();
        boolean fullyMatched = false;
        for (int i = 0; i < target.length(); i++) {
            int x = target.charAt(i) - 'a';
            if (freq[x] == 0)
                break;
            freq[x]--;
            prefix.append(target.charAt(i));
            if (i == target.length() - 1) {
                fullyMatched = true;
                break;
            }
        }

        if (!fullyMatched && prefix.length() < target.length()) {
            int pos = prefix.length();
            int x = target.charAt(pos) - 'a';
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] == 0)
                    continue;
                StringBuilder ans = new StringBuilder(prefix);
                ans.append((char) ('a' + c));
                freq[c]--;
                for (int j = 0; j < 26; j++) {
                    for (int k = 0; k < freq[j]; k++) {
                        ans.append((char) ('a' + j));
                    }
                }
                return ans.toString();
            }
        }

        for (int i = prefix.length() - 1; i >= 0; i--) {
            char ch = prefix.charAt(i);
            freq[ch - 'a']++;
            prefix.deleteCharAt(prefix.length() - 1);

            int x = target.charAt(i) - 'a';
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] == 0)
                    continue;
                StringBuilder ans = new StringBuilder(prefix);
                ans.append((char) ('a' + c));
                freq[c]--;
                for (int j = 0; j < 26; j++) {
                    for (int k = 0; k < freq[j]; k++) {
                        ans.append((char) ('a' + j));
                    }
                }
                return ans.toString();
            }
        }

        return "";
    }
}