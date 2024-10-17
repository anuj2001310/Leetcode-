public class Solution {
    public int FindLUSlength(string a, string b) {
        return (a.Equals(b)) ? -1 : Math.Max(a.Length, b.Length);
    }
}