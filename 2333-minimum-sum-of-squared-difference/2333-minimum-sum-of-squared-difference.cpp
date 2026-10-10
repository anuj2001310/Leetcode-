class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        long long k = k1 + k2;
        long long decreased = 0;
        long long ans = 0;
        int n = nums1.size();
        vector<long long> absdiff(n);
        for (int i = 0; i < n; i++) {
            ans += pow(abs(nums1[i] - nums2[i]), 2);
            absdiff[i] = abs(nums1[i] - nums2[i]);
        }
        sort(absdiff.begin(), absdiff.end(), greater<long long>());
        int sp = 1;
        int length = 1;
        while (sp < n) {
            long long diff = absdiff[sp - 1] - absdiff[sp];
            if (k - diff * length < 0) {
                break;
            } else {
                k = k - diff * length;
                decreased +=
                    (pow(absdiff[sp - 1], 2) - pow(absdiff[sp], 2)) * length;
            }
            length++;
            sp++;
        }
        while (k >= length && absdiff[sp - 1] != 0) {
            decreased += (2 * absdiff[sp - 1] - 1) * length;
            absdiff[sp - 1]--;
            k = k - length;
        }
        decreased += max(2 * absdiff[sp - 1] - 1, 0LL) * k;
        return ans - decreased;
    }
};