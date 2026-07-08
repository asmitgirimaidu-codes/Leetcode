# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[Optional[TreeNode]]
        """
        def buildTrees(start, end):
            if start > end:
                return [None]
            
            all_trees = []
            # Pick each number i as the root
            for i in range(start, end + 1):
                # Generate all left and right subtrees
                left_subtrees = buildTrees(start, i - 1)
                right_subtrees = buildTrees(i + 1, end)
                
                # Combine them
                for l in left_subtrees:
                    for r in right_subtrees:
                        current_tree = TreeNode(i)
                        current_tree.left = l
                        current_tree.right = r
                        all_trees.append(current_tree)
            
            return all_trees
        
        return buildTrees(1, n) if n > 0 else []