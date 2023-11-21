/*

Question
Formatted question description: https://leetcode.ca/all/272.html

Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST that are closest to the target. You may return the answer in any order.

You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

 

Example 1:



Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]
Example 2:

Input: root = [1], target = 0.000000, k = 1
Output: [1]
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104.
0 <= Node.val <= 109
-109 <= target <= 109
 

Follow up: Assume that the BST is balanced. Could you solve it in less than O(n) runtime (where n = total nodes)?

Algorithm
This tree is considered balanced if: the difference between heights of the left subtree and right subtree is not more than 1.

In-order
The comparison is completed during the in-order traversal.

When traversing to a node,

If the result array is less than k at this time, add this node value directly to the result,
If the absolute value of the difference between the node value and the target value is less than the absolute value of the difference between the first element of the result and the target value, indicating that the current value is closer to the target value, delete the first element and add the current node value to the end,
On the contrary, it means that the current value deviates more from the target value than all the values in the result res. Due to the characteristics of the in-order traversal, the subsequent values will deviate further, so the final result is directly returned at this time
Heap
A pair of difference diff and node value stored in the heap.

In order to traverse the binary tree (other traversal methods can also be used), and then calculate the absolute value of the difference between the target value and the target value for each node value.

Due to the nature of the maximum heap, the largest diff is automatically the first to maintain k pairs, if If there are more than k, delete the big pair at the front of the heap, and remove the node value in the pair for the k pairs left and store it in the result.
*/

// solution with heap and diff
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        priority_queue<pair<double, int>> q;
        inorder(root, target, k, q);
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    void inorder(TreeNode *root, double target, int k, priority_queue<pair<double, int>> &q) {
        if (!root) return;
        inorder(root->left, target, k, q);
        q.push({abs(root->val - target), root->val});
        if (q.size() > k) q.pop();
        inorder(root->right, target, k, q);
    }
};
