class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        def find(idx, arr, t, ds):
            if idx == len(arr):
                if t == 0:
                    res.append([_ for _ in ds])
                return
            
            if arr[idx] <= t:
                ds.append(arr[idx])
                find(idx, arr, t - arr[idx], ds)
                ds.pop()
            find(idx + 1, arr, t, ds)
        
        
        find(0, candidates, target, [])
        return res