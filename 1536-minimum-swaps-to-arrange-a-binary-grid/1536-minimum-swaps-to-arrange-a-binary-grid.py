class Solution(object):
    def minSwaps(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        # Calculate trailing zeros for each row
        zeros = []
        for row in grid:
            count = 0
            for j in range(n - 1, -1, -1):
                if row[j] == 0:
                    count += 1
                else:
                    break
            zeros.append(count)
        
        swaps = 0
        for i in range(n):
            target = n - 1 - i
            # Find the first row that meets the requirement
            found = False
            for j in range(i, n):
                if zeros[j] >= target:
                    # Move this row to position i
                    found = True
                    # Add number of adjacent swaps
                    swaps += (j - i)
                    # Shift the zeros array to reflect the movement
                    val = zeros.pop(j)
                    zeros.insert(i, val)
                    break
            
            if not found:
                return -1
                
        return swaps