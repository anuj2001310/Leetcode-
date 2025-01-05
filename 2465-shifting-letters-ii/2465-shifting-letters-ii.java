class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] prefix = new int[n + 1];

        for (int[] shift : shifts) {
            int st = shift[0];
            int ed = shift[1];
            int dr = shift[2];
            prefix[st] += (2 * dr - 1);
            prefix[ed + 1] -= (2 * dr - 1);
        }

        StringBuilder sb = new StringBuilder("");
        int currShift = 0;
        for (int i = 0; i < n; i++) {
            currShift = (currShift + prefix[i]) % 26;
            char ch = (char) ('a' + (s.charAt(i) - 'a' + currShift + 26) % 26);
            sb.append(ch);
        }
        return sb.toString();
    }
}