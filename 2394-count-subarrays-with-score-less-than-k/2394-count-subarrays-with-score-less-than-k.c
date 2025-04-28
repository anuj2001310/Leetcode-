typedef long long ll;
long long countSubarrays(int* nums, int numsSize, long long k) {
    ll res = 0, cnt = 0, sum = 0;
    int l = 0;
    for (int r = 0; r < numsSize; ++r) {
        sum += nums[r];
        cnt++;
        while (sum * cnt >= k) {
            sum -= nums[l++];
            cnt--;
        }
        res += cnt;
    }
    return res;
}