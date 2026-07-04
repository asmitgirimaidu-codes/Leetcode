class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        # Edge case: No zigzag needed
        if numRows == 1 or numRows >= len(s):
            return s
        
        # Initialize an array of strings for each row
        rows = [""] * numRows
        current_row = 0
        direction = 1  # 1 for down, -1 for up
        
        for char in s:
            rows[current_row] += char
            
            # Change direction if at top or bottom
            if current_row == 0:
                direction = 1
            elif current_row == numRows - 1:
                direction = -1
            
            current_row += direction
            
        return "".join(rows)