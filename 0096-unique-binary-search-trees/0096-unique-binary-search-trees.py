class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # G[i] will store the number of unique BSTs with i nodes
        G = [0] * (n + 1)
        
        # Base cases: 
        # An empty tree (0 nodes) is 1 unique structure
        # A tree with 1 node is 1 unique structure
        G[0] = 1
        G[1] = 1
        
        # Fill the DP table up to n
        for nodes in range(2, n + 1):
            for i in range(1, nodes + 1):
                # G[left_nodes] * G[right_nodes]
                G[nodes] += G[i - 1] * G[nodes - i]
                
        return G[n]