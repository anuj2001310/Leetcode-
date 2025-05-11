class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int n = arr.length, mask = (1 << 1);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if ((arr[i] & 1) != 0)
                cnt++;
            else
                cnt = 0;
            
            if (((cnt & 1) != 0) && ((mask & cnt) != 0))
                return true;
        }
        return false;
    }
}