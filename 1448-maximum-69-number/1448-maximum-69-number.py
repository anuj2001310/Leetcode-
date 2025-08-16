class Solution:
    def maximum69Number (self, num: int) -> int:
        arr = []
        while num:
            r = num % 10
            arr.insert(0, r)
            num //= 10
        
        for i in range(len(arr)):
            if arr[i] == 6:
                arr[i] = 9
                break
        
        for ele in arr:
            num = num * 10 + ele
        
        return num