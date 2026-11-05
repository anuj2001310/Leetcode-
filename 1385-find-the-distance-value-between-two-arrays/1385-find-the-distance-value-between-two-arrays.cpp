class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        int m = arr2.size();
        for (int num : arr1) {
            int idx =
                lower_bound(arr2.begin(), arr2.end(), num - d) - arr2.begin();

            if (idx < m && arr2[idx] <= num + d)
                continue;
            else
                ans++;
        }

        return ans;
    }
};