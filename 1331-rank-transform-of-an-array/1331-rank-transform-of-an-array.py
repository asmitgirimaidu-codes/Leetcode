class Solution(object):
    def arrayRankTransform(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        # Get sorted unique elements from the array
        sorted_unique = sorted(list(set(arr)))
        
        # Map each unique element to its rank (1-indexed)
        rank_map = {val: i + 1 for i, val in enumerate(sorted_unique)}
        
        # Replace each element in the original array with its rank
        return [rank_map[x] for x in arr]