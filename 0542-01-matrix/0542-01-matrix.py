from collections import deque

class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        if not mat:
            return mat
        
        m, n = len(mat), len(mat[0])
        queue = deque()
        # Initialize distance matrix
        dist = [[float('inf')] * n for _ in range(m)]
        
        # Add all 0s to the queue and set their distance to 0
        for r in range(m):
            for c in range(n):
                if mat[r][c] == 0:
                    dist[r][c] = 0
                    queue.append((r, c))
                    
        # Directions for neighbors (up, down, left, right)
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        # Multi-source BFS
        while queue:
            r, c = queue.popleft()
            
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                
                # If neighbor is within bounds and we found a shorter path
                if 0 <= nr < m and 0 <= nc < n and dist[nr][nc] > dist[r][c] + 1:
                    dist[nr][nc] = dist[r][c] + 1
                    queue.append((nr, nc))
                    
        return dist