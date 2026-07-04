from collections import deque, defaultdict

class Solution(object):
    def minScore(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        # Build an adjacency list where graph[u] = [(v, distance), ...]
        graph = defaultdict(list)
        for u, v, d in roads:
            graph[u].append((v, d))
            graph[v].append((u, d))
        
        # Initialize variables
        min_score = float('inf')
        visited = set()
        queue = deque([1])
        visited.add(1)
        
        # Perform BFS to find all nodes in the connected component of 1
        while queue:
            node = queue.popleft()
            
            for neighbor, distance in graph[node]:
                # Update the minimum score found so far
                min_score = min(min_score, distance)
                
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
                    
        return min_score