class Solution {
    public boolean judgeCircle(String moves) {
        int x = 0, y = 0;
        char[] arr = new char[26];
        for (char ch : moves.toCharArray())
            arr[ch - 'A']++;
        
        return (arr['L' - 'A'] == arr['R' - 'A'] && arr['U' - 'A'] == arr['D' - 'A']);
    }
}