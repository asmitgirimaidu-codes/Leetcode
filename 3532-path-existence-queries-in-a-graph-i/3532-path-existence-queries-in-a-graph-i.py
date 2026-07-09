class Solution(object):
    def pathExistenceQueries(self, n, nums, maxDiff, queries):
        """
        :type n: int
        :type nums: List[int]
        :type maxDiff: int
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        # comp[i] will store the component ID for node i
        comp = [0] * n
        
        # Iterate through the sorted array to assign component IDs
        for i in range(1, n):
            if nums[i] - nums[i - 1] <= maxDiff:
                # Same component as the previous node
                comp[i] = comp[i - 1]
            else:
                # New component begins
                comp[i] = comp[i - 1] + 1
        
        # Answer each query by comparing the component IDs of u and v
        ans = []
        for u, v in queries:
            ans.append(comp[u] == comp[v])
            
        return ans