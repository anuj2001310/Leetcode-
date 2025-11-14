long long maxProduct(int* nums, int numsSize) {
    typedef long long ll;
    ll max1 = 0;
    ll max2 = 0;

    for(int i = 0; i < numsSize; i++){
        ll absNum = nums[i] < 0 ? -nums[i] : nums[i];

        if (absNum > max2) {
            if (absNum > max1) {
                max2 = max1;
                max1 = absNum;
                } 
            else
                max2 = absNum;
            
        }
    }

    return (ll) max1 * max2 * 100000;
}