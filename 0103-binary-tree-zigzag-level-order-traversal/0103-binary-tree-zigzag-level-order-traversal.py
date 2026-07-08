import collections

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        result = []
        queue = collections.deque([root])
        left_to_right = True
        
        while queue:
            level_size = len(queue)
            current_level = collections.deque()
            
            for _ in range(level_size):
                node = queue.popleft()
                
                # Add to the level list based on current direction
                if left_to_right:
                    current_level.append(node.val)
                else:
                    current_level.appendleft(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            result.append(list(current_level))
            # Flip the direction for the next level
            left_to_right = not left_to_right
            
        return result