typedef long long ll;
long long maximumTripletValue(int* nums, int numsSize) {
    ll ans = 0, dmax = 0, imax = 0;
    for (int i = 0; i < numsSize; ++i) {
        ans = fmax(ans, dmax * nums[i]);
        dmax = fmax(dmax, imax - nums[i]);
        imax = fmax(imax, nums[i]);
    }
    return ans;
}