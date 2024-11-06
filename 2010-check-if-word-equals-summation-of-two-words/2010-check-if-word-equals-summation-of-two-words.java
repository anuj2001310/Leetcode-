class Solution {
    private String change(String str) {
        String ch = "";
        for (int i = 0; i < str.length(); ++i) {
            int curr = str.charAt(i) - 'a';
            ch += (char) (curr + '0');
        }
        return ch;
    }

    public boolean isSumEqual(String fw, String sw, String tw) {
        String f = change(fw);
        String s = change(sw);
        String t = change(tw);
        return Integer.parseInt(f) + Integer.parseInt(s) == Integer.parseInt(t);
    }
}