from collections import defaultdict
import math

class Solution(object):
    def maxPoints(self, points):
        """:type points: List[List[int]]
        :rtype: int
        """
        n = len(points)
        if n <= 2:
            return n
            
        max_points = 0
        
        for i in range(n):
            slopes = defaultdict(int)
            duplicates = 1
            curr_max = 0
            
            for j in range(i + 1, n):
                dx = points[j][0] - points[i][0]
                dy = points[j][1] - points[i][1]
                
                if dx == 0 and dy == 0:
                    duplicates += 1
                    continue
                    
                g = math.gcd(dx, dy)
                dx //= g
                dy //= g
                
                if dx < 0:
                    dx, dy = -dx, -dy
                elif dx == 0:
                    dy = abs(dy)
                    
                slopes[(dx, dy)] += 1
                curr_max = max(curr_max, slopes[(dx, dy)])
                
            max_points = max(max_points, curr_max + duplicates)
            
        return max_points