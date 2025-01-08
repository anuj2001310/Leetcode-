public class Solution {
    public int CountPrefixSuffixPairs(string[] words) {
        var cnt = 0;
        for (var i = 0; i < words.Length; ++i)
            for (var j = i + 1; j < words.Length; ++j)
                if (words[j].StartsWith(words[i]) && words[j].EndsWith(words[i]))
                    ++cnt;
        return cnt;
    }
}