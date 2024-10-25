class Solution(object):
    def removeSubfolders(self, folder):
        """
        :type folder: List[str]
        :rtype: List[str]
        """
        n = len(folder)
        folder.sort()
        list = []
        list.append(folder[0])

        for i in range(1, n):
            last = list[-1]
            if not folder[i].startswith(last + "/"):
                list.append(folder[i])
        
        return list