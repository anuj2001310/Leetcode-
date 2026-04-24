class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int l_cnt = 0, r_cnt = 0, _cnt = 0;

        int n = moves.length();

        for (int i = 0; i < n; i++) {
            if (moves.charAt(i) == 'L')
                l_cnt++;
            else if (moves.charAt(i) == 'R')
                r_cnt++;
            else
                _cnt++;
        }

        int mx = Math.max(l_cnt, r_cnt);
        int mn = Math.min(l_cnt, r_cnt);

        return (mx + _cnt - mn);
    }
}