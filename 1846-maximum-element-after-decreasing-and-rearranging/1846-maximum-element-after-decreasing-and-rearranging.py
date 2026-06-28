class Solution(object):
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        # Step 1: Sort the array to easily manage adjacent differences
        arr.sort()
        
        # Step 2: Set the first element to 1 as per the requirement
        arr[0] = 1
        
        # Step 3: Iterate and ensure arr[i] - arr[i-1] <= 1
        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1] + 1:
                arr[i] = arr[i - 1] + 1
        
        # The last element will be the maximum possible value
        return arr[-1]