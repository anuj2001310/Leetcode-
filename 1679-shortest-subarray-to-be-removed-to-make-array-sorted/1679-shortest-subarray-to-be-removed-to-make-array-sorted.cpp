class Solution {
private:
    bool isStrictlyDecres(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= nums[i - 1])
                return false;
        }
        return true;
    }
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (isStrictlyDecres(arr))
            return arr.size() - 1;
        if (isSorted(arr))
            return 0;

        int r = arr.size() - 2;
        while (r >= 0 && arr[r] <= arr[r + 1])
            r -= 1;

        int minLen = r + 1;
        for (int l = 1; l < r + 1; ++l) {
            while (r + 1 < arr.size() && arr[l - 1] > arr[r + 1])
                r++;

            minLen = fmin(minLen, r - l + 1);
            if (arr[l - 1] > arr[l])
                break;
        }

        return minLen;
    }
};

static const char a = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}();