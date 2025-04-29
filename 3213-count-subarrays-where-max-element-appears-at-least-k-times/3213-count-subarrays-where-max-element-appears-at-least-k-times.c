typedef long long ll;
long long countSubarrays(int* nums, int numsSize, int k) {
    ll ans = 0;
    int l = 0, curr = 0, r = 0, max = 0;
    for (int i = 0; i < numsSize; ++i)
        max = fmax(max, nums[i]);
    for (; r < numsSize; ++r) {
        curr += (nums[r] == max);
        while (curr >= k)
            curr -= (nums[l++] == max);
        ans += l;
    }
    return ans;
}