class Solution {
    protected int vowelcnt(String t) {
        int cnt = 0;
        for (char ch : t.toCharArray())
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                cnt++;
        return cnt;
    }

    public String reverseWords(String s) {

        int n = s.length();
        String[] words = s.split(" ");
        int match = vowelcnt(words[0]);
        StringBuilder sb = new StringBuilder(words[0]);
        for (int i = 1; i < words.length; ++i) {
            StringBuilder h = new StringBuilder("");
            h.append(words[i]);
            if (vowelcnt(words[i]) == match) {
                h.reverse();
            }
            sb.append(' ');
            sb.append(h);
        }
        //sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
}