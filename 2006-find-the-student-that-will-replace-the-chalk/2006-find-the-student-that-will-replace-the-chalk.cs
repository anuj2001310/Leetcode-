public class Solution {
    public int ChalkReplacer(int[] chalk, int k) {
        long tot = 0;
        foreach (int c in chalk)
            tot += c;
        int remain_after_crounds = Convert.ToInt32(k % tot);
        for (int i = 0; i < chalk.Length; ++i){
            if (remain_after_crounds < chalk[i])
                return i;
            remain_after_crounds -= chalk[i];
        }
        return -1;
    }
}