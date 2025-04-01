typedef long long ll;
ll answer = 0;

ll memo (int** questions, ll* dp, int idx, int n) {
    if (idx >= n)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    
    ll take = questions[idx][0];
    int nidx = idx + questions[idx][1] + 1;
    
    if (nidx < n)
        take += memo (questions, dp, nidx, n);
    ll skip = memo (questions, dp, idx + 1, n);
    
    answer = fmax(take, skip);
    return dp[idx] = fmax(take, skip);
}

long long mostPoints(int** questions, int n, int* questionsColSize) {
    ll* dp = (ll*)malloc(sizeof(ll) * (n + 1));
    for (int i = 0; i < n + 1; ++i)
        dp[i] = -1;
    
    memo (questions, dp, 0, n);
    
    free(dp);
    free(questions);
    return answer;
}