class Solution {
    public int maxSumDivThree(int[] nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 3 == 0) return sum;
        else if (sum % 3 == 1) {
            // case 1, remove smallest %= 1 or 2 %= 2
            TwoS mod2 = new TwoS();
            int mod1 = Integer.MAX_VALUE;
            for (int num : nums) {
                if (num % 3 == 2) mod2.add(num);
                else if (num % 3 == 1) mod1 = Math.min(mod1, num);
            }
            return Math.max(0, Math.max(sum - mod2.getSum(), sum - mod1));
        } 
        else {
            // case 2 remove 2 smallest %= 1 or % one smallest %= 2
            TwoS mod1 = new TwoS();
            int mod2 = Integer.MAX_VALUE;
            for (int num : nums) {
                if (num % 3 == 2) mod2 = Math.min(mod2, num);
                else if (num % 3 == 1) mod1.add(num);
            }
            return Math.max(0, Math.max(sum - mod1.getSum(), sum - mod2));
        }
    }
    
    public static class TwoS {
        int a;
        int b;
        
        public TwoS() {
            a = Integer.MAX_VALUE;
            b = Integer.MAX_VALUE;
        }
        
        public void add(int num) {
            if (num <= a) {
                b = a;
                a = num;
            } else if (num < b) {
                b = num;
            }
        }
        
        public int getSum() {
            if (a == Integer.MAX_VALUE || b == Integer.MAX_VALUE) return Integer.MAX_VALUE;
            return a + b;
        }
    }
}