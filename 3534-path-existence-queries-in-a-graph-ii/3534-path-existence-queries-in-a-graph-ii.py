class Solution(object):
    def pathExistenceQueries(self, n, nums, maxDiff, queries):
        """
        :type n: int
        :type nums: List[int]
        :type maxDiff: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        # Pair each number with its original index
        indexed_nums = sorted((val, idx) for idx, val in enumerate(nums))
        
        # Map original index to sorted position
        pos_in_sorted = [0] * n
        for sorted_idx, (val, orig_idx) in enumerate(indexed_nums):
            pos_in_sorted[orig_idx] = sorted_idx
            
        # Find the maximum reachable index to the right in the sorted array for each node
        # using a two-pointer / sliding window approach
        max_reach = [0] * n
        right = 0
        for i in range(n):
            while right < n and indexed_nums[right][0] - indexed_nums[i][0] <= maxDiff:
                right += 1
            max_reach[i] = right - 1
            
        # Sparse Table for binary lifting to find the minimum distance
        # dp[k][i] stores the furthest reachable sorted index from sorted index i in 2^k steps
        K = 18  # since n <= 10^5, 2^17 > 10^5
        dp = [[0] * n for _ in range(K)]
        
        for i in range(n):
            dp[0][i] = max_reach[i]
            
        for k in range(1, K):
            for i in range(n):
                dp[k][i] = dp[k - 1][dp[k - 1][i]]
                
        def get_min_distance(u, v):
            # Convert original indices to sorted indices
            su = pos_in_sorted[u]
            sv = pos_in_sorted[v]
            
            if su == sv:
                return 0
                
            # Ensure su < sv by swapping if necessary (since the graph is undirected)
            if su > sv:
                su, sv = sv, su
                
            # If even from su we can't reach sv, return -1
            if dp[K - 1][su] < sv:
                return -1
                
            steps = 0
            curr = su
            for k in range(K - 1, -1, -1):
                if dp[k][curr] < sv:
                    curr = dp[k][curr]
                    steps += (1 << k)
                    
            return steps + 1

        answer = []
        for u, v in queries:
            answer.append(get_min_distance(u, v))
            
        return answer