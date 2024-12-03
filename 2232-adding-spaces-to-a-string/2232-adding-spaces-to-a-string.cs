public class Solution {
    public string AddSpaces(string s, int[] spaces) {
        char[] newString = new char[s.Length + spaces.Length];
        int addedSpace = 0;
        int i = -1;
        int spaceIndex = 0;

        while (spaceIndex<spaces.Length && ++i<s.Length) {
            if (i == spaces[spaceIndex]) { 
                newString[i + addedSpace] = ' ';
                addedSpace++;
                spaceIndex++;
            }
            newString[i+addedSpace] = s[i];        
        }
        while(++i<s.Length)
            newString[i+addedSpace] = s[i];
        
        return new string(newString);
    }
}