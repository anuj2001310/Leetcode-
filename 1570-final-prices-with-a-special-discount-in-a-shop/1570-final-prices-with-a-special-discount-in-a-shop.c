/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int n = pricesSize;
    int *dis = (int*)calloc(n, sizeof(int));
    *returnSize = 0;
    for(int i = 0; i < n - 1; ++i){
        int discount = prices[i];
        for(int j = i + 1; j < n ; ++j){
            if(prices[j] <= prices[i]){
                discount = prices[i] - prices[j];
                break;
            }
        }
        dis[(*returnSize)++] = discount;
    }
    dis[(*returnSize)++] = prices[n - 1];
    return dis;
}