class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        int n = words.length;
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (char ch : words[i].toCharArray())
                s += (weights[ch - 'a']);
            
            int r = 25 - (s % 26);
            sb.append((char)(r + 'a'));
        }
        return sb.toString();
    }
}