/*


Description
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
According to the definition of LCA on Wikipedia: “The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Image text

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1

Output: 3

Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

Image text

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4

Output: 5

Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [1,2], p = 1, q = 2

Output: 1

Constraints:

The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q exist in the tree.
Solution - Set
Use a set to store nodes. Start from p and obtain all the nodes from p to the root node using the nodes’ parents. Then start from q and move towards the root. If a node is already in the set, then the node is a common ancestor of p and q. The first common ancestor that is in the set is the lowest common ancestor of p and q.

Solution - 2 pointers
The idea is as follows: we will use 2 pointers (pointerA, pointerB) that go from nodeA and nodeB upwards respectively. Assume nodeA locates at a shallower level than nodeB, i.e. depth(nodeA) < depth(nodeB), pointerA will reach the top quicker than pointerB.

Suppose the difference in depth between nodeA and nodeB is diff.

By the time pointerA reaches the top, pointerB will be diff levels behind. Now if pointerA resets its path and continues upwards from nodeB instead of nodeA, it will need diff steps to reach the level of nodeA, by which time pointerB has already caught up and will be at the same level of pointerA (pointerB restarts from nodeA after reaching the top).

Now the only thing to do is to compare pointerA and pointerB on the way up. If pointerA and pointerB points to the same node, we’ve found the lowest common ancestor.

*/


// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
// Time: O(N)
// Space: O(1)
class Solution {
    int getLength(Node *p) {
        int ans = 0;
        for (; p->parent; p = p->parent, ++ans);
        return ans;
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int a = getLength(p), b = getLength(q);
        if (a < b) swap(a, b), swap(p, q);
        a -= b;
        while (a-- > 0) p = p->parent;
        while (p != q) p = p->parent, q = q->parent;
        return p;
    }
};