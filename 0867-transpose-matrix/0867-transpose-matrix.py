class Solution(object):
    def transpose(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        # Get dimensions of the original matrix
        rows = len(matrix)
        cols = len(matrix[0])
        
        # Create a new matrix with swapped dimensions (cols x rows)
        # We fill it with zeros initially
        result = [[0 for _ in range(rows)] for _ in range(cols)]
        
        # Iterate through the original matrix and map to the new positions
        for i in range(rows):
            for j in range(cols):
                result[j][i] = matrix[i][j]
                
        return result