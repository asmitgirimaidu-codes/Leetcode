class Solution(object):
    def areSimilar(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: bool
        """
        n = len(mat[0])
        # After n shifts, any row returns to its original state.
        # We only care about the remainder of shifts.
        k %= n
        
        if k == 0:
            return True
            
        for row in mat:
            # Create the shifted version of the row
            # Even index: left shift, Odd index: right shift
            # However, the problem implies the shift happens to all rows 
            # following the same cyclic logic. 
            # Actually, simply checking if row[i] == row[(i + k) % n] 
            # for all elements works because the shift is uniform.
            for i in range(n):
                if row[i] != row[(i + k) % n]:
                    return False
        
        return True