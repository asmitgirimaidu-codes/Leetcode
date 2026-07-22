# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertionSortList(self, head):
        """:type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return head
            
        dummy = ListNode(0)
        dummy.next = head
        curr = head
        
        while curr and curr.next:
            if curr.val <= curr.next.val:
                curr = curr.next
            else:
                target = curr.next
                curr.next = target.next
                
                prev = dummy
                while prev.next.val <= target.val:
                    prev = prev.next
                    
                target.next = prev.next
                prev.next = target
                
        return dummy.next