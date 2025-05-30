class Solution {
  bool isArraySpecial(List<int> nums) {
    int n = nums.length;
    for (int i = 1; i < n; i++) {
        if ((nums[i] & 1) == (nums[i - 1] & 1))
            return false;
    }
    return true;
  }
}