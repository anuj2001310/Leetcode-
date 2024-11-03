public class Solution {
    public bool RotateString(string s, string goal) {
        if (s.Length != goal.Length)
            return false;
        string concat = s + s;
        if (concat.Contains(goal))
            return true;
        
        return false;
    }
}