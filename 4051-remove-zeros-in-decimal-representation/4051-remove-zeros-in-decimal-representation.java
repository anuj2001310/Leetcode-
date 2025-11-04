class Solution {
    public long removeZeros(long n) {
        long ans = 0;
        StringBuilder sb = new StringBuilder("");
        for (; n > 0; ) {
            int r = (int) (n % 10);
            n /= 10;
            if (r == 0)
                continue;
            char ch = (char) r;
            sb.append(ch);
        }
        sb.reverse();
        for (char ch : sb.toString().toCharArray()) {
            int num = ch;
            //System.out.println(num);
            ans = 10 * ans + num;
        }
        return ans;
    }
}