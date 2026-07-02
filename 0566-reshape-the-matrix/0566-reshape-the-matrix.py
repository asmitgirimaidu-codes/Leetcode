class Solution(object):
    def matrixReshape(self, mat, r, c):
        m = len(mat)
        n = len(mat[0])
        
        # If the total number of elements doesn't match, return original
        if m * n != r * c:
            return mat
        
        # Initialize the reshaped matrix
        reshaped = [[0] * c for _ in range(r)]
        
        # Fill the new matrix
        for k in range(m * n):
            # Map 1D index k to original (i, j) and new (nr, nc)
            reshaped[k // c][k % c] = mat[k // n][k % n]
            
        return reshaped