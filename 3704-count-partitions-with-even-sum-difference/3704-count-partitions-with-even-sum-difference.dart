class Solution {
  int countPartitions(List<int> nums) {
    int s = nums.reduce((a, b) => a + b);
    if (s % 2 != 0)
        return 0;

    int left = 0;
    int cnt = 0;

    for (int i = 0; i < nums.length - 1; i++) {
        left += nums[i];
        int temp = s - 2 * left;
        if ((temp.abs() & 1) == 0) {
            cnt++;
        }
    }

    return cnt;
  }
}