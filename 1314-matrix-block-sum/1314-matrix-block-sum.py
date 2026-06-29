class Solution(object):
    def matrixBlockSum(self, mat, k):
        m, n = len(mat), len(mat[0])
        
        # Create a prefix sum matrix of size (m+1) x (n+1)
        # P[i][j] will store sum of mat[0...i-1][0...j-1]
        P = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(m):
            for j in range(n):
                P[i + 1][j + 1] = mat[i][j] + P[i][j + 1] + P[i + 1][j] - P[i][j]
        
        answer = [[0] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                # Define the boundaries of the block
                r1, c1 = max(0, i - k), max(0, j - k)
                r2, c2 = min(m, i + k + 1), min(n, j + k + 1)
                
                # Use inclusion-exclusion to get the sum in O(1)
                answer[i][j] = P[r2][c2] - P[r1][c2] - P[r2][c1] + P[r1][c1]
                
        return answer