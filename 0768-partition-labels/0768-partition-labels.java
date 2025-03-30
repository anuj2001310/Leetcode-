class Solution {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        List<Integer> ans = new ArrayList<>();
        var end = new int[26];

        for (int i = 0; i < n; ++i) {
            int key = s.charAt(i) - 'a';
            end[key] = i;
        }
        int prev = -1, last = -1;
        for (int i = 0; i < n; ++i) {
            int key = s.charAt(i) - 'a';
            if (end[key] > last)
                last = end[key];
            if (i == last) {
                ans.add(i - prev);
                prev = i;
            }
        }
        return ans;
    }
}