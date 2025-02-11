public class Solution {
    public string RemoveOccurrences(string s, string part) {
        var n = s.Length;
        var p = part.Length;
        var stringBuilder = new StringBuilder();

        for (var i = 0; i < n; i++) {
            stringBuilder.Append(s[i]);
            var remove = true;
            if (stringBuilder.Length < p)
                continue;

            for (var j = 1; j <= p; j++) {
                if (stringBuilder[^j] == part[^j])
                    continue;
                remove = false;
                break;
            }

            if (remove)
                stringBuilder.Length -= p;
        }

        return stringBuilder.ToString();
    }
}