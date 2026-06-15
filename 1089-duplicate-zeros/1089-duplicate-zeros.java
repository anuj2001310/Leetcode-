class Solution {
    public void duplicateZeros(int[] arr) {
        int n = arr.length;
        int[] nums = Arrays.copyOf(arr, n);

        int j = 0;

        for (int i = 0; i < n && j < n; i++) {
            arr[j++] = nums[i];

            if (nums[i] == 0 && j < n) {
                arr[j++] = 0;
            }
        }
    }
}