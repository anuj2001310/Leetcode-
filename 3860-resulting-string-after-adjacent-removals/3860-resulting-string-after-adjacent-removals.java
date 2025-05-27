class Solution {
    public String resultingString(String s) {
        Deque<Character> dq = new ArrayDeque<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (!dq.isEmpty() && ((Math.abs(dq.getLast() - s.charAt(i)) == 1) || (Math.abs(dq.getLast() - s.charAt(i)) == 25)))
                dq.pollLast();
            else
                dq.offerLast(s.charAt(i));
        }
        StringBuilder sb = new StringBuilder("");
        while (!dq.isEmpty()) {
            Character st = dq.getFirst();
            sb.append(st);
            dq.removeFirst();
        }
        return sb.toString();
    }
}