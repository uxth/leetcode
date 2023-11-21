/*

Question
Formatted question description: https://leetcode.ca/all/255.html

Given an array of unique integers preorder, return true if it is the correct preorder traversal sequence of a binary search tree.

 

Example 1:



Input: preorder = [5,2,1,3,6]
Output: true
Example 2:

Input: preorder = [5,2,6,1,3]
Output: false
 

Constraints:

1 <= preorder.length <= 104
1 <= preorder[i] <= 104
All the elements of preorder are unique.
 

Follow up: Could you do it using only constant space complexity?

Algorithm
First set a minimum value low, then traverse the array, if the current value is less than the minimum value low, return false.

For the root node, push it onto the stack, and then traverse back,

If the number encountered is smaller than the element at the top of the stack, it means that it is the point of its left subtree and continues to be pushed onto the stack.

Until the number encountered is greater than the top element of the stack, then it is the value on the right child. You need to find the right subtree of which node,

So update the low value and delete the top element of the stack, and then continue to compare with the next top element,

If it is still greater than, continue to update the low value and delete the top of the stack, until the stack is empty or the current stack top element is greater than the current value, stop, push the current value,

In this way, if it does not return false before traversing the entire array, return true at the end.
*/

// OJ: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool verifyPreorder(vector<int>& A) {
        stack<int> s;
        int mn = INT_MIN;
        for (int n : A) {
            if (n < mn) return false;
            while (s.size() && s.top() < n) {
                mn = s.top();
                s.pop();
            }
            s.push(n);
        }
        return true;
    }
};