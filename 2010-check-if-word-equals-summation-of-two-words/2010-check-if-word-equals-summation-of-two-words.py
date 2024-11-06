class Solution(object):
    def isSumEqual(self, fw, sw, tw):
        """
        :type firstWord: str
        :type secondWord: str
        :type targetWord: str
        :rtype: bool
        """
        def change(str):
            ch = ""
            for w in str:
                curr = ord(w) - ord('a')
                ch += chr(curr + 48)
            
            return ch
        
        f = change(fw)
        s = change(sw)
        t = change(tw)
        
        return int(f) + int(s) == int(t)
