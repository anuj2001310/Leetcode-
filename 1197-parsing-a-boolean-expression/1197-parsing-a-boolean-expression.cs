public class Solution {
    // "|(&(t,f,t),t)"
    public bool ParseBoolExpr(string expression) {
        if (expression == "t") return true;
        if (expression == "f") return false;

        var op = expression[0];
        var expressionsList = ParseInput(expression);
    
        return op switch {
            '&' => expressionsList.All(ParseBoolExpr),
            '|' => expressionsList.Any(ParseBoolExpr),
            '!' => !ParseBoolExpr(expressionsList[0]),
            _ => ParseBoolExpr(expressionsList[0])
        };
    }

    private List<string> ParseInput(string input) {
        var trimmed = input.TrimStart('!', '|', '&').Trim('(', ')');
        var builder = new StringBuilder();
        var result = new List<string>();
        var depth = 0;

        foreach (var ch in trimmed) {
            if (ch == '(') depth++;
            if (ch == ')') depth--;

            if (depth == 0 && ch == ',') {
                result.Add(builder.ToString());
                builder.Clear();
            }
            else
                builder.Append(ch);
        }

        result.Add(builder.ToString());

        return result;
    }
}