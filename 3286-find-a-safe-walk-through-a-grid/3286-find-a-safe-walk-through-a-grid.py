from collections import deque

class Solution(object):
    def findSafeWalk(self, grid, health):
        m, n = len(grid), len(grid[0])
        # dist[i][j] stores the minimum health lost to reach (i, j)
        dist = [[float('inf')] * n for _ in range(m)]
        
        # Starting point
        start_cost = grid[0][0]
        dist[0][0] = start_cost
        
        queue = deque([(0, 0)])
        
        while queue:
            r, c = queue.popleft()
            
            for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                nr, nc = r + dr, c + dc
                
                if 0 <= nr < m and 0 <= nc < n:
                    weight = grid[nr][nc]
                    if dist[r][c] + weight < dist[nr][nc]:
                        dist[nr][nc] = dist[r][c] + weight
                        if weight == 0:
                            queue.appendleft((nr, nc))
                        else:
                            queue.append((nr, nc))
                            
        return dist[m-1][n-1] < health