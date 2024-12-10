class Solution:
    def maximumLength(self, s: str) -> int:
        res = -1
        dic = {}
        l = 0
        for i, c in enumerate(s):
            if c not in dic:
                dic[c] = []
                heapq.heapify(dic[c])
            if c != s[l]:
                ml = i - l
                heapq.heappush(dic[s[l]], ml)
                if len(dic[s[l]]) > 3:
                    heapq.heappop(dic[s[l]])
                l = i
        ml = len(s) - l
        heapq.heappush(dic[s[l]], ml)
        if len(dic[s[-1]]) > 3:
            heapq.heappop(dic[s[-1]])
        for c in dic:
            arr = dic[c]
            arr.sort(reverse=True)
            res = max(res, arr[0] - 2)
            if len(arr) > 2:
                if arr[0] == arr[1] and arr[1] == arr[2]:
                    res = max(res, arr[0])
                if arr[0] > arr[1]:
                    res = max(res, arr[1])
                else:
                    res = max(res, arr[1] - 1)
            elif len(arr) == 2:
                if arr[0] > arr[1]:
                    res = max(res, arr[1])
                else:
                    
                    res = max(res, arr[1] - 1)
        return res if res > 0 else -1