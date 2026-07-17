# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def sumRootToLeaf(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(node, current_sum):
            if not node:
                return 0
            
            # Update current binary path value
            current_sum = (current_sum << 1) | node.val
            
            # If leaf node, return the path value
            if not node.left and not node.right:
                return current_sum
            
            # Continue DFS to children and sum up values
            return dfs(node.left, current_sum) + dfs(node.right, current_sum)
        
        return dfs(root, 0)