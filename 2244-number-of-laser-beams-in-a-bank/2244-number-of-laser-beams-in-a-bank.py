class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        arr = []
        for i in range(len(bank)):
            cnt = bank[i].count("1")
            if cnt == 0:
                continue
            arr.append(cnt)
        
        res = 0
        #print(arr)
        for j in range(len(arr) - 1):
            t = arr[j] * arr[j + 1]
            res += t
        return res