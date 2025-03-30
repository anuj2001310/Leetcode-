public class Solution {
    public IList<int> PartitionLabels(string s) {
        int n = s.Length;
        IList<int> labels = [];
        int[] end = new int[26];
        for (int i = 0; i < n; i++){
            int key = s[i] - 'a';
            end[key] = i;
        }
        int prev = -1, last = -1;
        for (int i = 0; i < n; i++){
            int key = s[i] - 'a';
            if (end[key] > last)
                last = end[key];
            if (i == last){
                labels.Add(i - prev);
                prev = i;
            }
        }

        return labels;
    }
}