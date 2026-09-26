class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        n = len(s)
        i = 0
        d = defaultdict(str)
        for lst in knowledge:
            u, v = lst[0], lst[1]

            d[u] = v
        
        #print(d)
        res = []
        while i < n:
            if s[i] == '(':
                t = ''
                j = i + 1
                while s[j] != ')' and j < n:
                    t += s[j]
                    j += 1
                
                i = j
                #print(t)
                if t in d:
                    res.append(d[t])
                else:
                    res.append('?')
            
            else:
                res.append(s[i])
            
            i += 1
        
        return ''.join(res)