/*

Given a node from a cyclic linked list which is sorted in ascending order,
 write a function to insert a value into the list such that it remains a cyclic sorted list.
 The given node can be a reference to any single node in the list, and may not be necessarily the smallest value in the cyclic list.

 If there are multiple suitable places for insertion, you may choose any place to insert the new value.
 After the insertion, the cyclic list should remain sorted.

 If the list is empty (i.e., given node is null), you should create a new single cyclic list and return the reference to that single node.
 Otherwise, you should return the original given node.

 The following example may help you understand the problem better:

 In the figure above, there is a cyclic sorted list of three elements.
 You are given a reference to the node with value 3, and we need to insert 2 into the list.

 The new node should insert between node 1 and node 3.
 After the insertion, the list should look like this, and we should still return node 3.

Algorithm
In the ascending phase, look for a position larger than the front and smaller than the rear. The turning point is to see if the insertVal is the maximum or minimum value, and it is added at the turning point.

If you switch back to the head and haven’t found it, it’s always flat, just add it in front of the head.

The corner case is emphasized in the title, that is, when the linked list is empty, we insert a node to generate a new circular ordered linked list.

Then we can deal with this special case first. It is relatively simple, that is, create a new node, and then Just point the next pointer to yourself. Well, let’s look at the situation where the given linked list is not empty. The most common situation is that the node value to be inserted is between two ordered node values [a, b], then as long as a <= insertVal < = b is fine. Because it is a circular and orderly linked list, the node value will not rise all the time.

When it reaches a certain node, it is the maximum value, but the next node is the minimum value, which is the example in the question, from node 4 to node At 1, it is down. Then at this inflection point, the insertion value insertVal will have two special cases, which are greater than or equal to the maximum value, or less than or equal to the minimum value. For example, when the inserted value is 5 or 0, both cases are inserted in the knot. After point 4, you can put them together for processing. And if it is less than the maximum value or greater than the minimum value, it is the general case above and will not be processed here, so we only need to detect if it belongs to one of the above two cases, then break the loop and insert the node processing Can

*/


// OJ: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
// Time: O(N)
// Space: O(U) where U is the number of unique numbers in the list
class Solution {
public:
    Node* insert(Node* head, int val) {
        auto node = new Node(val);
        node->next = node;
        if (!head) return node;
        map<int, Node*> m;
        auto p = head;
        do {
            m[p->val] = p;
            p = p->next;
        } while (p != head);
        auto it = m.upper_bound(val);
        if (it == m.end() || it == m.begin()) {
            p = m.rbegin()->second;
        } else {
            p = prev(it)->second;
        }
        node->next = p->next;
        p->next = node;
        return head;
    }
};