class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        previous = -1
        s = s.split()
        
        for i in s:
            if i.isdigit():
                current = int(i)
                if current <= previous:
                    return False
                previous = current

        return True