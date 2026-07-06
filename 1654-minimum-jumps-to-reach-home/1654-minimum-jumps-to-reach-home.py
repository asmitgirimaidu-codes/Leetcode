from collections import deque

class Solution(object):
    def minimumJumps(self, forbidden, a, b, x):
        """
        :type forbidden: List[int]
        :type a: int
        :type b: int
        :type x: int
        :rtype: int
        """
        # Forbidden set for O(1) lookup
        forbidden_set = set(forbidden)
        # Queue stores: (current_position, jumped_back_last, number_of_jumps)
        queue = deque([(0, False, 0)])
        # Visited stores: (position, jumped_back_last)
        visited = {(0, False)}
        
        # Upper bound: The bug won't need to go beyond this limit
        max_limit = 4000 + max(a, b)
        
        while queue:
            curr, jumped_back, jumps = queue.popleft()
            
            if curr == x:
                return jumps
            
            # Option 1: Jump Forward
            next_f = curr + a
            if next_f <= max_limit and next_f not in forbidden_set and (next_f, False) not in visited:
                visited.add((next_f, False))
                queue.append((next_f, False, jumps + 1))
                
            # Option 2: Jump Backward (only if last jump was not backward)
            if not jumped_back:
                next_b = curr - b
                if next_b >= 0 and next_b not in forbidden_set and (next_b, True) not in visited:
                    visited.add((next_b, True))
                    queue.append((next_b, True, jumps + 1))
                    
        return -1