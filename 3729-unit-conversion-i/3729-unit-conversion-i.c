/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const int mod = 1000000007;
typedef struct pair {
    int first;
    int second;
} pair;

pair* init(int first, int second) {
    pair* p = (pair*)malloc(sizeof(pair));
    p->first = first;
    p->second = second;
    return p;
}

int* baseUnitConversions(int** conversions, int conversionsSize, int* conversionsColSize, int* returnSize) {
    int n = conversionsSize;
    int* ans = (int*)calloc(sizeof(int), n + 1);
    ans[0] = 1;
    *returnSize = 1;

    int* dp = (int*)calloc(sizeof(int), n + 1);
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    dp[0] = 1;

    pair** adj = (pair**)malloc(sizeof(pair*) * (n + 1));
    for (int i = 0; i < n; i++) {
        int f = conversions[i][0];
        int t = conversions[i][1];
        int r = conversions[i][2];

        adj[t] = init(f, r);
    }
    
    int call(int idx, int* dp, pair** adj) {
        if(dp[idx] != -1) 
            return dp[idx];
        return dp[idx] = 1LL * adj[idx]->second * call(adj[idx]->first, dp, adj) %mod;
    }
    
    for (int i = 1; i <= n; i++) {
        int cost = call(i, dp, adj);
        ans[(*returnSize)++] = cost;
    }  

    return ans;
}