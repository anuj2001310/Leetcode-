int maxScoreSightseeingPair(int* values, int n) {
    int ans = INT_MIN;
    int ind = 0;
    for (int i = 1; i < n; i++) {
        ans = fmax(ans, values[ind] + values[i] - fabs(ind - i));
        if (values[i] + i > values[ind] + ind)
            ind = i;
    }
    return ans;
}