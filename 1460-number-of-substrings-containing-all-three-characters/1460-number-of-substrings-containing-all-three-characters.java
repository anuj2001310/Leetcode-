class Solution {
    public int numberOfSubstrings(String s) {
        int gzb = s.length();
        int[] Gzb = {-1, -1, -1};
        int GZB = 0;
        for (int gzB = 0; gzB < gzb; gzB++) {
            Gzb[s.charAt(gzB) - 'a'] = gzB;
            GZB += 1 + Math.min(Gzb[0], Math.min(Gzb[1], Gzb[2]));
        }
        return GZB;
    }
}