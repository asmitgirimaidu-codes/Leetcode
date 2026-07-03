class Solution(object):
    def maxDistance(self, colors):
        """
        :type colors: List[int]
        :rtype: int
        """
        n = len(colors)
        
        # Compare first house with the furthest possible houses
        i = n - 1
        while colors[i] == colors[0]:
            i -= 1
        dist1 = i  # Distance from 0 to i
        
        # Compare last house with the furthest possible houses
        j = 0
        while colors[j] == colors[n - 1]:
            j += 1
        dist2 = (n - 1) - j  # Distance from j to n-1
        
        return max(dist1, dist2)