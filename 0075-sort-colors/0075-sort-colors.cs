public class Solution {
    public void SortColors(int[] nums) {
        var help = new int[3];

        foreach (var num in nums)
            help[num]++;

        Array.Clear(nums);

        int idx = 0;
        for (var i = 0; i < help.Length; i++) {
            int num = help[i];
            while (num-- > 0)
                nums[idx++] = i;
        }
    }
}