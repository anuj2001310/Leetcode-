class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = version1.split('.')
        version2 = version2.split('.')

        l = min(len(version1), len(version2))
        # print(l)

        for i in range(l):
            if int(version1[i]) > int(version2[i]):
                return 1
            elif int(version1[i]) < int(version2[i]):
                return -1
        
        if len(version1) > l:
            for i in range(l, len(version1)):
                if int(version1[i]) > 0:
                    return 1
            return 0
        elif len(version2) > l:
            for i in range(l, len(version2)):
                if int(version2[i]) > 0:
                    return -1
            return 0
        else:
            return 0