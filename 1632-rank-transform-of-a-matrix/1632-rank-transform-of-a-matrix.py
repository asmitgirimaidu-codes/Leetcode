import collections

class Solution(object):
    def matrixRankTransform(self, matrix):
        m, n = len(matrix), len(matrix[0])
        parent = {}

        def find(i):
            if parent[i] != i:
                parent[i] = find(parent[i])
            return parent[i]

        def union(i, j):
            root_i, root_j = find(i), find(j)
            if root_i != root_j:
                parent[root_i] = root_j

        # Group indices by value
        val_map = collections.defaultdict(list)
        for r in range(m):
            for c in range(n):
                val_map[matrix[r][c]].append((r, c))

        row_max = [0] * m
        col_max = [0] * n

        for val in sorted(val_map.keys()):
            coords = val_map[val]
            parent = {r: r for r in range(m)}
            parent.update({c + m: c + m for c in range(n)})
            
            for r, c in coords:
                union(r, c + m)
            
            # Group components
            components = collections.defaultdict(list)
            for r, c in coords:
                components[find(r)].append((r, c))
            
            for root in components:
                # Rank is max of current row/col maxes + 1
                new_rank = 1
                for r, c in components[root]:
                    new_rank = max(new_rank, row_max[r] + 1, col_max[c] + 1)
                
                # Apply new rank
                for r, c in components[root]:
                    row_max[r] = col_max[c] = new_rank
                    matrix[r][c] = new_rank
                    
        return matrix