class Solution {
    public int maxScore(String s) {
        int ones = 0;
        int tempScore = s.charAt(0)=='0' ? 1 : 0;
        int score = tempScore;
        for(int i=1;i<s.length()-1;i++){
            if(s.charAt(i) == '0')
                tempScore++;
            else{
                ones++;
                tempScore--;
            }
            if(tempScore > score)
                score = tempScore;
        }
        ones+= (s.charAt(s.length()-1) == '1' ? 1 : 0);
        return ones + score;
    }
}