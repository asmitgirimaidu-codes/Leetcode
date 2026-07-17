class Solution(object):
    def gcdValues(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[int]
        :rtype: List[int]
        """
        max_num = max(nums)
        # 1. Count frequencies
        freq = [0] * (max_num + 1)
        for x in nums:
            freq[x] += 1
            
        # 2. Count pairs with GCD as multiple of i
        # g[i] will store the number of pairs with gcd exactly i
        g = [0] * (max_num + 1)
        
        # Iterate backwards from max_num to 1
        for i in range(max_num, 0, -1):
            count_multiples = 0
            for j in range(i, max_num + 1, i):
                count_multiples += freq[j]
            
            # Total pairs with GCD as a multiple of i
            total_pairs_with_gcd_multiple_of_i = (count_multiples * (count_multiples - 1)) // 2
            
            # Inclusion-Exclusion: subtract counts of multiples (2i, 3i, ...)
            for j in range(2 * i, max_num + 1, i):
                total_pairs_with_gcd_multiple_of_i -= g[j]
            
            g[i] = total_pairs_with_gcd_multiple_of_i
            
        # 3. Create prefix sum for binary search
        prefix_sum = [0] * (max_num + 1)
        for i in range(1, max_num + 1):
            prefix_sum[i] = prefix_sum[i - 1] + g[i]
            
        # 4. Answer queries using binary search
        import bisect
        ans = []
        for q in queries:
            # Find the smallest index i such that prefix_sum[i] > q
            ans.append(bisect.bisect_right(prefix_sum, q))
            
        return ans