class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return 0
        
        min_val, max_val = min(nums), max(nums)
        if min_val == max_val:
            return 0
        
        # Calculate size of buckets and number of buckets
        n = len(nums)
        bucket_size = max(1, (max_val - min_val) // (n - 1))
        bucket_count = (max_val - min_val) // bucket_size + 1
        
        # Initialize buckets
        buckets_min = [float('inf')] * bucket_count
        buckets_max = [float('-inf')] * bucket_count
        
        # Populate buckets
        for x in nums:
            idx = (x - min_val) // bucket_size
            buckets_min[idx] = min(buckets_min[idx], x)
            buckets_max[idx] = max(buckets_max[idx], x)
            
        # Find the maximum gap
        max_gap = 0
        previous_max = min_val
        for i in range(bucket_count):
            # Skip empty buckets
            if buckets_min[i] == float('inf'):
                continue
            
            # Gap between current bucket's min and previous bucket's max
            max_gap = max(max_gap, buckets_min[i] - previous_max)
            previous_max = buckets_max[i]
            
        return max_gap