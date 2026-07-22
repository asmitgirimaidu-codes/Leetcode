# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """:type head: Optional[ListNode]
        :type x: int
        :rtype: Optional[ListNode]
        """
        # Create two dummy heads for two partitions
        before_head = ListNode(0)
        before = before_head
        after_head = ListNode(0)
        after = after_head
        
        current = head
        while current:
            if current.val < x:
                before.next = current
                before = before.next
            else:
                after.next = current
                after = after.next
            current = current.next
            
        # Connect the two partitions
        after.next = None
        before.next = after_head.next
        
        return before_head.next