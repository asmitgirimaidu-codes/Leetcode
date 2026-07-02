from collections import defaultdict

class Solution(object):
    def maxIncreasingCells(self, mat):
        m, n = len(mat), len(mat[0])
        # Group coordinates by their values
        val_map = defaultdict(list)
        for r in range(m):
            for c in range(n):
                val_map[mat[r][c]].append((r, c))
        
        # row_max[r] stores the max path length ending in row r
        # col_max[c] stores the max path length ending in column c
        row_max = [0] * m
        col_max = [0] * n
        
        # Sort values to process in increasing order
        sorted_vals = sorted(val_map.keys())
        
        for val in sorted_vals:
            cells = val_map[val]
            # Calculate new path lengths for all cells with this value
            new_paths = []
            for r, c in cells:
                new_paths.append(max(row_max[r], col_max[c]) + 1)
            
            # Update the row and column maximums
            for (r, c), path in zip(cells, new_paths):
                row_max[r] = max(row_max[r], path)
                col_max[c] = max(col_max[c], path)
                
        return max(max(row_max), max(col_max))