class Solution(object):
    def decodeCiphertext(self, encodedText, rows):
        """
        :type encodedText: str
        :type rows: int
        :rtype: str
        """
        if rows == 1 or not encodedText:
            return encodedText
            
        n = len(encodedText)
        cols = n // rows
        res = []
        
        # Traverse along the diagonals starting from each column in the first row
        for start_col in range(cols):
            r, c = 0, start_col
            while r < rows and c < cols:
                res.append(encodedText[r * cols + c])
                r += 1
                c += 1
                
        # Remove trailing spaces from the original text
        return "".join(res).rstrip()
        