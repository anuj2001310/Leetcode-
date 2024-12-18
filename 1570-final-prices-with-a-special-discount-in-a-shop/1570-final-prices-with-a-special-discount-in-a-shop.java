class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] help = new int[n];
        int x = 0;
        for (int i = 0; i < n - 1; i++) {
            int dis = prices[i];
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    dis = prices[i] - prices[j];
                    break;
                }
            }
            help[x++] = dis;
        }
        help[x] = prices[n - 1];
        return help;
    }
}