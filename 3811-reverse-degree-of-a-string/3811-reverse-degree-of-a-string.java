class Solution {
    public int reverseDegree(String s) {
        int rev = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i)
            rev += ((26 - (s.charAt(i) - 'a')) * (i + 1));
        return rev;
    }
}