class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + ((h - l) >> 1);
            if (nums[mid] == target)
                return mid;

            //Left Part Sorted hai
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target <= nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            //Right Part Sorted hai
            else {
                if (nums[mid] <= target && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
}