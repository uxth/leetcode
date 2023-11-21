/*

If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.

Example 1:
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
Example 2:
Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.
Companies:
Alibaba

Related Topics:
Tree

Similar Questions:

Path Sum (Easy)
Path Sum II (Medium)
Binary Tree Maximum Path Sum (Hard)
Path Sum III (Easy)


*/

// OJ: https://leetcode.com/problems/path-sum-iv/
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n / 10] = n % 10;
        }
        int sum = 0;
        for (int n : nums) {
            int d = n / 100, p = n / 10 % 10, v = m[d * 10 + p];
            int left = (d + 1) * 10 + p * 2 - 1, right = left + 1;
            if (m.count(left)) m[left] += v;
            if (m.count(right)) m[right] += v;
            if (m.count(left) == 0 && m.count(right) == 0) sum += v;
        }
        return sum;
    }
};
