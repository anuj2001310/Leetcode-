class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        n = len(image)
        m = len(image[0])

        initial = image[sr][sc]
        ans = image
        q = deque()
        q.append((sr, sc))
        ans[sr][sc] = color
        while q:
            curr = q.popleft()
            r = curr[0]
            c = curr[1]
            for i in range(len(dirs)):
                nr = r + dirs[i][0]
                nc = c + dirs[i][1]
                if nr >= 0 and nr < n and nc >= 0 and nc < m and image[nr][nc] == initial and ans[nr][nc] != color:
                    q.append((nr, nc))
                    ans[nr][nc] = color
        
        return ans
        