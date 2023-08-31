#
# @lc app=leetcode id=24 lang=python3
#
# [24] Swap Nodes in Pairs
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        dummy = ListNode(0)
        dummy.next, head = head, dummy
        while head.next and head.next.next:
            a, b = head.next, head.next.next
            head.next, a.next, b.next, head = b, b.next, a, a
        return dummy.next
# @lc code=end

