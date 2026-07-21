class Solution(object):
    def survivedRobotsHealths(self, positions, healths, directions):
        """
        :type positions: List[int]
        :type healths: List[int]
        :type directions: str
        :rtype: List[int]
        """
        n = len(positions)
        # Store tuples of (position, health, direction, original_index)
        robots = sorted(zip(positions, healths, directions, range(n)))
        
        stack = []
        for pos, h, dir, idx in robots:
            if dir == 'R':
                stack.append([pos, h, dir, idx])
            else:
                # Current robot is moving 'L', check collisions with 'R' robots in stack
                while stack and stack[-1][2] == 'R' and h > 0:
                    top_pos, top_h, top_dir, top_idx = stack[-1]
                    if top_h > h:
                        stack[-1][1] -= 1
                        h = 0
                        break
                    elif top_h < h:
                        stack.pop()
                        h -= 1
                    else:
                        stack.pop()
                        h = 0
                        break
                if h > 0:
                    stack.append([pos, h, dir, idx])
                    
        # Sort surviving robots by their original input indices
        stack.sort(key=lambda x: x[3])
        return [r[1] for r in stack]
        