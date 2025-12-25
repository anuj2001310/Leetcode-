class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        long cnt = 0;
        Integer[] happy = new Integer[happiness.length];
        for (int i = 0; i < happiness.length; i++)
            happy[i] = happiness[i];
        Arrays.sort(happy, Collections.reverseOrder());
        cnt = (long) happy[0];
        for (int i = 1; i < k && (happy[i] - i) > 0; i++)
            cnt += (long) happy[i] - i;
        return cnt;
    }
}