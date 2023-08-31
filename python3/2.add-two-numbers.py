#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        resultlist = curr = ListNode(0) #we need two varibles because if only one variable is used we might loose reference to the head
        carry = 0
        while l1 or l2 or carry: # not none
            if l1 is not None:
                carry += l1.val
                l1 = l1.next #increase value of l1
            if l2 is not None:
                carry += l2.val
                l2 = l2.next
            curr.next = ListNode(carry%10)  #retur remainder of division
            curr = curr.next
            carry = carry//10  #returns floor value of division
            
        return resultlist.next
# @lc code=end

