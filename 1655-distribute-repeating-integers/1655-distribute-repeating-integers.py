from collections import Counter

class Solution(object):
    def canDistribute(self, nums, quantity):
        """
        :type nums: List[int]
        :type quantity: List[int]
        :rtype: bool
        """
        # 1. Get frequencies of available numbers
        counts = list(Counter(nums).values())
        
        # 2. Sort quantity descending to optimize pruning
        quantity.sort(reverse=True)
        
        def backtrack(q_idx):
            # If all customers are satisfied
            if q_idx == len(quantity):
                return True
            
            # 3. Try to assign current customer to a frequency group
            for i in range(len(counts)):
                if counts[i] >= quantity[q_idx]:
                    # Choose
                    counts[i] -= quantity[q_idx]
                    
                    # Explore
                    if backtrack(q_idx + 1):
                        return True
                    
                    # Un-choose (Backtrack)
                    counts[i] += quantity[q_idx]
                    
                    # Optimization: If the group was empty, or didn't lead to a solution,
                    # don't try assigning this customer to other empty/identical groups.
                    if counts[i] == 0:
                        break
            return False
        
        return backtrack(0)