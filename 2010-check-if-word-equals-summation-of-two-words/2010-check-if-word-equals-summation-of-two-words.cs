public class Solution {
    public bool IsSumEqual(string firstWord, string secondWord, string targetWord) {
        int value(string str) {
            int v = 0;
            for (int i = 0; i < str.Length; ++i)
                v = v * 10 + (str[i] - 'a');
            
            return v;
        }

        return value(firstWord) + value(secondWord) == value(targetWord);
    }
}