# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxPathSum(self, root):
        """:type root: Optional[TreeNode]
        :rtype: int
        """
        self.max_sum = float('-inf')
        
        def dfs(node):
            if not node:
                return 0
                
            # Compute max path sum of left and right subtrees
            # Ignore paths with negative sums by taking max with 0
            left_gain = max(0, dfs(node.left))
            right_gain = max(0, dfs(node.right))
            
            # Price of path containing current node as the highest point
            current_max_path = node.val + left_gain + right_gain
            
            # Update global maximum path sum
            self.max_sum = max(self.max_sum, current_max_path)
            
            # Return max sum of path extending from this node downwards
            return node.val + max(left_gain, right_gain)
            
        dfs(root)
        return self.max_sum