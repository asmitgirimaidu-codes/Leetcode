class Solution(object):
    def findDifferentBinaryString(self, nums):
        """
        :type nums: List[str]
        :rtype: str
        """
        # Build the result string character by character
        res = []
        for i in range(len(nums)):
            # If the i-th string has '0' at index i, put '1' in our result
            # If it has '1', put '0'
            if nums[i][i] == '0':
                res.append('1')
            else:
                res.append('0')
                
        return "".join(res)