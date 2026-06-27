class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # Ensure nums1 is the smaller array to optimize binary search
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
            
        m, n = len(nums1), len(nums2)
        low, high = 0, m
        
        while low <= high:
            i = (low + high) // 2
            j = (m + n + 1) // 2 - i
            
            # Values around the partition
            maxLeft1 = float('-inf') if i == 0 else nums1[i-1]
            minRight1 = float('inf') if i == m else nums1[i]
            
            maxLeft2 = float('-inf') if j == 0 else nums2[j-1]
            minRight2 = float('inf') if j == n else nums2[j]
            
            # Correct partition found
            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                # If total length is odd
                if (m + n) % 2 == 1:
                    return float(max(maxLeft1, maxLeft2))
                # If total length is even
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0
            
            # Adjust binary search range
            elif maxLeft1 > minRight2:
                high = i - 1
            else:
                low = i + 1