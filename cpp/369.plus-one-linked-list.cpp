/*

Question
Formatted question description: https://leetcode.ca/all/369.html

Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

 

Example 1:

Input: head = [1,2,3]
Output: [1,2,4]
Example 2:

Input: head = [0]
Output: [1]
 

Constraints:

The number of nodes in the linked list is in the range [1, 100].
0 <= Node.val <= 9
The number represented by the linked list does not contain leading zeros except for the zero itself. 
Algorithm
Reverse
The head of the table is high digit. Now let’s add 1 operation. The difficulty of this problem is that the linked list cannot access the elements by coordinates, and can only be done by traversal.

Then we think in reverse, if the end of the chain is high, then it is much more convenient to add 1 operation, and you can directly perform calculations while traversing.

So what we can do is to reverse the linked list first, and now the end of the chain is high, we add 1 to the end of the processing operation, and then reverse the linked list back.

First non-9 digit, +1, then set 0 for following
Traverse the linked list and find the first number from the right that is not 9.

If you can’t find such a number, it means that all the numbers are 9, then create a new node with a value of 0 in the header, add 1 to it, and then set all the numbers on the right to 0. for example:

For example, 1->2->3, then the first number that is not 9 is 3. Add 1 to 3 to become 4, and there is no node on the right, so no processing is done, and 1->2-> 4.

For example, 8->9->9, find the first number that is not 9 is 8, and add 1 to become 9, and then set all the following numbers to 0 to get the result 9->0- >0.

For example, in the case of 9->9->9, if a number other than 9 is not found, then create a new node with a value of 0 in the front, add 1 to the process to become 1, and set all the following numbers 0, get 1->0->0->0.

*/

// OJ: https://leetcode.com/problems/plus-one-linked-list/
// Time: O(N)
// Space: O(1)
class Solution {
private:
    ListNode *reverse(ListNode *head) {
        ListNode dummy(0);
        while (head) {
            auto p = head;
            head = head->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }
public:
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode *p = head;
        int carry = 1;
        while (carry) {
            p->val++;
            carry = p->val / 10;
            p->val %= 10;
            if (!p->next) break;
            p = p->next;
        }
        if (carry) p->next = new ListNode(1);
        return reverse(head);
    }
};
