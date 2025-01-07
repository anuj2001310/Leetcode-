public class Solution {
    public IList<string> StringMatching(string[] words) {
        IList<string> ans = new List<string>();
        var st = new HashSet<string>();
        int n = words.Length;

        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < n; ++j) {
                if (i != j) {
                    if (words[i].Contains(words[j]))
                        st.Add(words[j]);
                }
            }
        }
        foreach (var str in st)
            ans.Add(str);
        return ans;
    }
}