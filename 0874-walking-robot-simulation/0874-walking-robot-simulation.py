class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        # Convert obstacles to a set of tuples for O(1) lookup
        obs_set = set(tuple(obs) for obs in obstacles)
        
        # Directions: North, East, South, West
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        curr_dir = 0  # Starts facing North
        x, y = 0, 0
        max_dist_sq = 0
        
        for cmd in commands:
            if cmd == -2:
                # Turn left 90 degrees
                curr_dir = (curr_dir - 1) % 4
            elif cmd == -1:
                # Turn right 90 degrees
                curr_dir = (curr_dir + 1) % 4
            else:
                # Move forward k units one by one
                dx, dy = directions[curr_dir]
                for _ in range(cmd):
                    next_x = x + dx
                    next_y = y + dy
                    if (next_x, next_y) in obs_set:
                        break
                    x, y = next_x, next_y
                    max_dist_sq = max(max_dist_sq, x**2 + y**2)
                    
        return max_dist_sq