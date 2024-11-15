class Solution {
      private boolean isSorted(ArrayList<Integer> nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums.get(i) <= nums.get(i - 1))
                return false;
        }
        return true;
    }

    public boolean areNumbersAscending(String s) {
        String tokens[] = s.split(" ");
        ArrayList<Integer> ls = new ArrayList<>();

        for (String tk : tokens) {
            if (tk.charAt(0) > '0' && tk.charAt(0) <= '9')
                ls.add(Integer.parseInt(tk));
        }
        
        return isSorted(ls);
    }
}