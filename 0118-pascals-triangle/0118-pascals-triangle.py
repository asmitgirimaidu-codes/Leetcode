class Solution(object):
    def generate(self, numRows):
        """:type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
            
        res = [[1]]
        
        for i in range(1, numRows):
            prev_row = res[-1]
            current_row = [1]
            
            for j in range(1, len(prev_row)):
                current_row.append(prev_row[j - 1] + prev_row[j])
                
            current_row.append(1)
            res.append(current_row)
            
        return res