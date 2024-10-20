class Solution {
    private String help(char ch, String res) {
        if (ch == '!')
            return ((res.charAt(0) == 't') ? "f" : "t");
        if (ch == '&')
            for (int i = 0; i < res.length(); ++i)
                if (res.charAt(i) == 'f')
                    return "f";

        if (ch == '|')
            for (int i = 0; i < res.length(); ++i)
                if (res.charAt(i) == 't')
                    return "t";
        return res;
    }

    public boolean parseBoolExpr(String expression) {
        Stack<Character> stack = new Stack<>();
        int n = expression.length();
        for (int i = 0; i < n; i++) {
            if (expression.charAt(i) == ',')
                continue;
            if (expression.charAt(i) != ')')
                stack.push(expression.charAt(i));
            else {
                StringBuilder sb = new StringBuilder();
                while (stack.peek() != '(')
                    sb.insert(0, stack.pop());
                stack.pop();
                char ch = stack.pop();
                String res = help(ch, sb.toString());
                stack.push(res.charAt(0));
            }
        }
        return stack.pop().toString().equals("t");
    }
}