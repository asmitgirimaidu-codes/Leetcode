class Solution(object):
    def removeCoveredIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        # Sort by start time ascending, then by end time descending
        intervals.sort(key=lambda x: (x[0], -x[1]))
        
        count = 0
        max_r = 0
        
        for _, r in intervals:
            # If current interval's end is greater than max_r,
            # it is not covered.
            if r > max_r:
                count += 1
                max_r = r
                
        return count