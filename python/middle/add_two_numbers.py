# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        new_list = ListNode(0)
        tmp_head = new_list
        carry = 0
        while l1 and l2:
            new_node = ListNode((l1.val + l2.val + carry)%10)
            carry = (l1.val + l2.val + carry)/10
            tmp_head.next = new_node
            l1 = l1.next
            l2 = l2.next
            tmp_head = tmp_head.next
        
        while l1:
            new_node = ListNode((l1.val + carry) % 10)
            carry = (l1.val + carry)/10
            tmp_head.next = new_node
            l1 = l1.next
            tmp_head = tmp_head.next
        
        while l2:
            new_node = ListNode((l2.val + carry) % 10)
            carry = (l2.val + carry)/10
            tmp_head.next = new_node
            l2 = l2.next
            tmp_head = tmp_head.next
        
        if carry:
            new_node = ListNode(carry)
            tmp_head.next = new_node
        return new_list.next
        
