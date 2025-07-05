class Solution {
    public int findLucky(int[] arr) {
        int[] hash = new int[501];
        for (int i = 0; i < arr.length; ++i)
            hash[arr[i]]++;
        for (int i = 500; i > 0; --i)
            if (hash[i] == i)
                return i;
        return -1;
    }
}