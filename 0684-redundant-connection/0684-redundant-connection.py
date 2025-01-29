class Solution(object):
    def find(self, dsu, v):
        if dsu[v] == -1:
            return v
        # Path compression
        dsu[v] = self.find(dsu, dsu[v])
        return dsu[v]
        
    
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        n = len(edges)
        dsu = [-1] * (n + 1)  # Initializing DSU array
        
        for edge in edges:
            parent_x = self.find(dsu, edge[0])
            parent_y = self.find(dsu, edge[1])
            
            if parent_x == parent_y:
                return edge  # Found the redundant edge
            else:
                # Union operation (attach one tree to the other)
                dsu[parent_x] = parent_y
        
        return [0, 0]  # Fallback case (though not needed in valid inputs)
