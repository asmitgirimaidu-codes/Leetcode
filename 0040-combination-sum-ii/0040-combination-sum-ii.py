class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        results = []
        # Sort to handle duplicates easily
        candidates.sort()
        
        def backtrack(remaining, start_index, path):
            if remaining == 0:
                results.append(list(path))
                return
            
            for i in range(start_index, len(candidates)):
                # Skip duplicates: if the current candidate is the same as the previous 
                # one in the same loop level, skip it to avoid duplicate sets.
                if i > start_index and candidates[i] == candidates[i - 1]:
                    continue
                
                # If current candidate exceeds remaining, no need to check further
                if candidates[i] > remaining:
                    break
                
                path.append(candidates[i])
                # Move to i + 1 because each number can only be used once
                backtrack(remaining - candidates[i], i + 1, path)
                path.pop()
                
        backtrack(target, 0, [])
        return results