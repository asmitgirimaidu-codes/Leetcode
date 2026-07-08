# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if not root:
            return 0
        
        # If both children are None, this is a leaf
        if not root.left and not root.right:
            return 1
        
        # If left child is None, we must recurse into the right subtree
        if not root.left:
            return self.minDepth(root.right) + 1
        
        # If right child is None, we must recurse into the left subtree
        if not root.right:
            return self.minDepth(root.left) + 1
        
        # If both children exist, take the minimum of the two paths
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1