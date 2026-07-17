class Solution(object):
    def numSpecial(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        rows = len(mat)
        cols = len(mat[0])
        
        row_counts = [0] * rows
        col_counts = [0] * cols
        
        # 1. Count 1s in each row and column
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 1:
                    row_counts[i] += 1
                    col_counts[j] += 1
                    
        # 2. Check for special positions
        special_count = 0
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 1 and row_counts[i] == 1 and col_counts[j] == 1:
                    special_count += 1
                    
        return special_count
        