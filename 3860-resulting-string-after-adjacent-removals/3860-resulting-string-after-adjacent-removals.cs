public class Solution {
    public string ResultingString(string s) {

    bool func(char x, char y) {
        int val = Math.Abs(x - y);
        return val == 1 || val == 25;
    }
        
        var sb = new StringBuilder("");
        var dq = new List<char>();
        foreach (var ch in s) {
            if (dq.Count > 0 && (func(dq[dq.Count - 1], ch)))
                dq.RemoveAt(dq.Count - 1);
            else
                dq.Add(ch);
        }

        foreach (var ch in dq)
            sb.Append(ch);
        return sb.ToString();
    }
}