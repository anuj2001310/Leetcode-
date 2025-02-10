public class Solution {
    public string ClearDigits(string s) {
        
        if(string.IsNullOrEmpty(s))
            return "";

        StringBuilder sb = new StringBuilder();
        foreach(var c in s)
        {
            if(Char.IsDigit(c) && sb.Length > 0)
                sb.Length--;
            else if(Char.IsLetter(c))
                sb.Append(c);
        }

        return sb.ToString();
    }
}