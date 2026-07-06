class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        results = []
        
        def backtrack(remaining, start_index, path):
            if remaining == 0:
                results.append(list(path))
                return
            if remaining < 0:
                return
            
            for i in range(start_index, len(candidates)):
                # Choose the candidate
                path.append(candidates[i])
                # Recurse: we pass 'i' as start_index because we can reuse the same element
                backtrack(remaining - candidates[i], i, path)
                # Backtrack: remove the last element to explore other possibilities
                path.pop()
        
        backtrack(target, 0, [])
        return results