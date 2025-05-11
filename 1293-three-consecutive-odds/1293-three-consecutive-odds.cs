public class Solution {
    public bool ThreeConsecutiveOdds(int[] arr) {
        int mask = (1 << 1);
        int cnt = 0;
        foreach (var ele in arr) {
            if ((ele & 1) != 0)
                cnt++;
            else
                cnt = 0;
            
            if (((cnt & 1) != 0) && ((mask & cnt) != 0))
                return true;
        }
        return false;
    }
}