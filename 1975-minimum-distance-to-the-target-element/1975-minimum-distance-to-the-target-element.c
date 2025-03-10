int getMinDistance(int* nums, int n, int target, int start) {
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (nums[i] == target)
            ans = fmin(ans, fabs(i - start));
    }
    return ans;
}