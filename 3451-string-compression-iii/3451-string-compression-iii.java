class Solution {
    public String compressedString(String word) {
        StringBuilder sb = new StringBuilder("");
        int i = 0;
        while (i < word.length()) {
            int cnt = 1;
            char curr = word.charAt(i);
            while ((i + 1) < word.length() && word.charAt(i + 1) == curr && cnt < 9) {
                cnt++;
                i++;
            }
            sb.append((char) (cnt + '0'));
            sb.append(curr);
            i++;
        }
        return sb.toString();
    }
}