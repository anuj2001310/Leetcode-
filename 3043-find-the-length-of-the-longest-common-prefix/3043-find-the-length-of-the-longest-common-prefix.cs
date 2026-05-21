public class Solution {
    public int LongestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<int> set = new HashSet<int>();

        foreach (int num in arr1) {
            int n = num;
            while (n>0) {
                if (set.Contains(n)) break;
                set.Add(n);
                n/=10;
            }
        }

        int max = 0;
        foreach (int num in arr2) {
            int n = num;
            while (n>0) {
                if (set.Contains(n)) {
                    if (n > max) max = n;
                    break;
                }
                n/=10;
            }     
        }

        int res = 0;

        while (max>0) {
            res++;
            max/=10;
        }

        return res;
    }
}