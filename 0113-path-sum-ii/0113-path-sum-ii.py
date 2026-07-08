# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: List[List[int]]
        """
        result = []
        
        def backtrack(node, remaining_sum, current_path):
            if not node:
                return
            
            # Add current node to the path
            current_path.append(node.val)
            
            # Check if it's a leaf node and the path sum matches
            if not node.left and not node.right and remaining_sum == node.val:
                result.append(list(current_path))
            else:
                # Continue searching in children
                backtrack(node.left, remaining_sum - node.val, current_path)
                backtrack(node.right, remaining_sum - node.val, current_path)
            
            # Backtrack: remove the current node before returning to parent
            current_path.pop()
            
        backtrack(root, targetSum, [])
        return result