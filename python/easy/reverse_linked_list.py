# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        new_head = ListNode(0)
        new_head.next = head
        curr = head
        next = head.next
        while(next != None):
            tmp = next.next
            curr.next = tmp
            next.next = new_head.next
            new_head.next = next
            next = curr.next
        return new_head.next
        
