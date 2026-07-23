class Solution(object):
    def countCompleteComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        visited = [False] * n
        complete_count = 0
        
        for i in range(n):
            if not visited[i]:
                # BFS/DFS to find all nodes and edges in the current component
                component_nodes = []
                queue = [i]
                visited[i] = True
                
                # Using a queue for BFS
                head = 0
                while head < len(queue):
                    curr = queue[head]
                    head += 1
                    component_nodes.append(curr)
                    for neighbor in adj[curr]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            queue.append(neighbor)
                            
                # Count total edges within this component
                edge_count = 0
                for node in component_nodes:
                    edge_count += len(adj[node])
                # Each undirected edge is counted twice
                edge_count //= 2
                
                m = len(component_nodes)
                # A connected component is complete if edge_count == m * (m - 1) // 2
                if edge_count == m * (m - 1) // 2:
                    complete_count += 1
                    
        return complete_count