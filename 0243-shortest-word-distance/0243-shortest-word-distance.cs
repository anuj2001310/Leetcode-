public class Solution {
    public int ShortestDistance(string[] wordsDict, string word1, string word2) {
        var minDistance = Int32.MaxValue;
        var lastWord1 = -1;
        var lastWord2 = -1;
        for (var i = 0; i < wordsDict.Length; i++) {
            var word = wordsDict[i];
            if (word.Equals(word1)) {
                lastWord1 = i;
                if (lastWord2 > -1) {
                    minDistance = Math.Min(minDistance, Math.Abs(lastWord2 - lastWord1));
                }
            }
            if (word.Equals(word2)) {
                lastWord2 = i;
                if (lastWord1 > -1) {
                    minDistance = Math.Min(minDistance, Math.Abs(lastWord2 - lastWord1));
                }
            }
        }
        return minDistance;
    }
}