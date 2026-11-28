class Solution {
    int minPrice;

    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;
        int maxFac = 0;
        for (var item : items)
            maxFac = Math.max(maxFac, item[0]);
        int[] fre = new int[maxFac + 1];
        for (var item : items)
            fre[item[0]]++;
        for (int i = 1; i <= maxFac; i++) {
            if (fre[i] > 0) {
                for (int j = i * 2; j <= maxFac; j += i) {
                    fre[i] += fre[j];
                }
            }
        }

        Arrays.sort(items, (a, b) -> Integer.compare(a[1], b[1]));
        minPrice = items[0][1];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            // subtract copy of itself
            int copy = fre[items[i][0]] - 1;
            if (price - minPrice > minPrice)
                break;

            int take = Math.min(copy, budget / price);
            ans += (take * 2);
            budget -= (take * price);
        }
        ans += (budget / minPrice);
        return ans;
    }
}