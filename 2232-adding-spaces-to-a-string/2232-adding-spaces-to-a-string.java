class Solution {
    public String addSpaces(String s, int[] spaces) {
        int i = 0, k = 0;
        StringBuilder sb = new StringBuilder("");
        while (i < s.length() && k < spaces.length) {
            if (i == spaces[k]) {
                sb.append(" ");
                k++;
            }
            sb.append(s.charAt(i));
            i++;
        }
        
        while (i < s.length())
            sb.append(s.charAt(i++));
        return sb.toString();
    }
}