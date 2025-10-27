class Solution {
    public int[] shortestToChar(String s, char c) {
        int n = s.length();
        int[] ans = new int[n];
        HashSet<Integer> hs = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == c)
                hs.add(i);
        }
        for (int i = 0; i < n; ++i) {
            int dis = Integer.MAX_VALUE;
            for (Integer d : hs)
                dis = Math.min(dis, Math.abs(i - d));
            ans[i] = dis;
        }
        return ans;
    }
}