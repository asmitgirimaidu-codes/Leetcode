from collections import deque, defaultdict

class Solution(object):
    def specialNodes(self, n, edges, x, y, z):
        # Build adjacency list
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        def get_distances(start_node):
            distances = [-1] * n
            distances[start_node] = 0
            queue = deque([start_node])
            
            while queue:
                u = queue.popleft()
                for v in adj[u]:
                    if distances[v] == -1:
                        distances[v] = distances[u] + 1
                        queue.append(v)
            return distances
        
        # Get distances from x, y, and z to all nodes
        dist_x = get_distances(x)
        dist_y = get_distances(y)
        dist_z = get_distances(z)
        
        special_count = 0
        for i in range(n):
            # Collect and sort the three distances
            dists = sorted([dist_x[i], dist_y[i], dist_z[i]])
            # Pythagorean condition: a^2 + b^2 = c^2
            if dists[0]**2 + dists[1]**2 == dists[2]**2:
                special_count += 1
                
        return special_count