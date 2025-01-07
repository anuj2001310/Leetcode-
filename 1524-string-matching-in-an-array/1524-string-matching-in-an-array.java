class Solution {
    public List<String> stringMatching(String[] words) {
        Set<String> st = new HashSet<>();
        List<String> ans = new ArrayList<>();
        int n = words.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (words[i].contains(words[j]))
                        st.add(words[j]);
                }
            }
        }

        for (String str : st)
            ans.add(str);
        return ans;
    }
}