/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (42.28%)
 * Likes:    3139
 * Dislikes: 144
 * Total Accepted:    284.6K
 * Total Submissions: 658.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 * 
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* sortList(ListNode* head, ListNode* tail = nullptr)
  {
    if (head != tail) {
      ListNode* smaller;
      ListNode** smaller_next = &smaller;
      for (ListNode** prev = &head->next; *prev != tail; ) {
        if (head->val > (**prev).val) {
          *smaller_next = *prev;
          smaller_next = &((**smaller_next).next);
          *prev = (**prev).next;
        } else {
          prev = &((**prev).next);
        }
      }

      *smaller_next = head;
      head->next = sortList(head->next, tail);
      head = sortList(smaller, head);
    }
    return head;
  }
};
// @lc code=end

