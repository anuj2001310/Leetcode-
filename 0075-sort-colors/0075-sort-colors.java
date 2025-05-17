class Solution {
    public void sortColors(int[] nums) {
        int[] arr = new int[3];
        for (int u : nums)
            arr[u]++;
        int idx = 0;
        for (int i = 0; i < arr[0]; i++)
            nums[idx++] = 0;
        for (int i = 0; i < arr[1]; i++)
            nums[idx++] = 1;

        for (int i = 0; i < arr[2]; i++)
            nums[idx++] = 2;

    }
}