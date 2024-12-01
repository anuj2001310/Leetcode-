class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        n = len(arr)
        dict = {}
        for i in range(n):
            comp, res = arr[i] * 2, arr[i] / 2
            if comp in dict or res in dict:
                return True
            else:
                dict[arr[i]] = dict.get(arr[i], 0) + 1
        return False