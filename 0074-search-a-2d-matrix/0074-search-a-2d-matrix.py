class Solution(object):
    def searchMatrix(self, matrix, target):
        """:type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or not matrix[0]:
            return False
        
        m = len(matrix)
        n = len(matrix[0])
        
        low = 0
        high = (m * n) - 1
        
        while low <= high:
            mid = (low + high) // 2
            # Map 1D index 'mid' back to 2D matrix coordinates
            row = mid // n
            col = mid % n
            val = matrix[row][col]
            
            if val == target:
                return True
            elif val < target:
                low = mid + 1
            else:
                high = mid - 1
                
        return False