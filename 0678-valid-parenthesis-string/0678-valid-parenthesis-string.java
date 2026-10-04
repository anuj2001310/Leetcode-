class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> star = new Stack<>();
        Stack<Integer> open = new Stack<>();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '*')
                star.push(i);
            else if (s.charAt(i) == '(')
                open.push(i);
            else {
                if (!open.isEmpty())
                    open.pop();
                else if (!star.isEmpty())
                    star.pop();
                else
                    return false;
            }
        }
        while (!open.isEmpty()) {
            if (star.isEmpty())
                return false;
            else if (open.peek() < star.peek()) {
                open.pop();
                star.pop();
            } else
                return false;
        }
        return true;
    }
}