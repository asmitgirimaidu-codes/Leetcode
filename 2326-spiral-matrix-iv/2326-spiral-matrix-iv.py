# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def spiralMatrix(self, m, n, head):
        """
        :type m: int
        :type n: int
        :type head: Optional[ListNode]
        :rtype: List[List[int]]
        """
        # Initialize the matrix with -1
        matrix = [[-1 for _ in range(n)] for _ in range(m)]
        
        # Directions: right, down, left, up
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        curr_dir = 0
        r, c = 0, 0
        
        curr = head
        while curr:
            matrix[r][c] = curr.val
            
            # Calculate next potential position
            next_r = r + directions[curr_dir][0]
            next_c = c + directions[curr_dir][1]
            
            # Check if next position is within bounds and empty
            if 0 <= next_r < m and 0 <= next_c < n and matrix[next_r][next_c] == -1:
                r, c = next_r, next_c
            else:
                # Rotate direction clockwise
                curr_dir = (curr_dir + 1) % 4
                r += directions[curr_dir][0]
                c += directions[curr_dir][1]
            
            curr = curr.next
            
        return matrix
        