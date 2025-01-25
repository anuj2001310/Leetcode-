using System;
using System.Linq;

public class Solution {
    public int[] LexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.Length;
        
        var help = new (int value, int index)[n];
        for (int i = 0; i < n; i++)
            help[i] = (nums[i], i);
        

        Array.Sort(help, (a, b) => a.value.CompareTo(b.value));

        int[] res = new int[n];
        int prev = int.MinValue;
        var pos = new System.Collections.Generic.List<int>();

        int s = 0, e = 0;
        while (e < n) {
            pos.Add(help[e].index);
            prev = help[e].value;
            e++;

            if (e == n || help[e].value - prev > limit) {
                pos.Sort();
                foreach (var idx in pos)
                    res[idx] = help[s++].value;

                pos.Clear();
            }
        }

        return res;
    }
}

//