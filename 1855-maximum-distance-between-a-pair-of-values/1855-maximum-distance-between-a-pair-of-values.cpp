class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        int max_diff = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] > nums2[j]) {
                i++;
                continue;
            }
            max_diff = max(max_diff, j - i);
            j++;
        }
        return max_diff;
    }
};