/*
 * @lc app=leetcode id=1104 lang=cpp
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 *
 * https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/
 *
 * algorithms
 * Medium (71.96%)
 * Likes:    399
 * Dislikes: 161
 * Total Accepted:    18.8K
 * Total Submissions: 26.1K
 * Testcase Example:  '14'
 *
 * In an infinite binary tree where every node has two children, the nodes are
 * labelled in row order.
 * 
 * In the odd numbered rows (ie., the first, third, fifth,...), the labelling
 * is left to right, while in the even numbered rows (second, fourth,
 * sixth,...), the labelling is right to left.
 * 
 * 
 * 
 * Given the label of a node in this tree, return the labels in the path from
 * the root of the tree to the node with that label.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: label = 14
 * Output: [1,3,4,14]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: label = 26
 * Output: [1,2,6,10,26]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= label <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 0;
        while (1 << level <= label) ++level;
        vector<int> res(level);
        for(; label >= 1; label /= 2, --level) {
            res[level - 1] = label;
            label = (1 << level) - 1 - label + (1 << (level - 1));
        }
        return res;
    }
};
// @lc code=end

