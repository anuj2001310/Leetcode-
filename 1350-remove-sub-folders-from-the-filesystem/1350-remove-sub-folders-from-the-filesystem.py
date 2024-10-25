class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        n = len(folder)
        folder.sort()
        list = []
        list.append(folder[0])

        for i in range(1, n):
            last = list[-1]
            if not folder[i].startswith(last + "/"):
                list.append(folder[i])
        
        return list