/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 *
 * https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (76.13%)
 * Likes:    647
 * Dislikes: 26
 * Total Accepted:    63.5K
 * Total Submissions: 81.8K
 * Testcase Example:  '[2,1,4]\r\n[1,0,3]\r'
 *
 * Given two binary search trees root1 and root2.
 * 
 * Return a list containing all the integers from both trees sorted in
 * ascending order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [2,1,4], root2 = [1,0,3]
 * Output: [0,1,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
 * Output: [-10,0,0,1,2,5,7,10]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root1 = [], root2 = [5,1,7,0,2]
 * Output: [0,1,2,5,7]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root1 = [0,-10,10], root2 = []
 * Output: [-10,0,10]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root1 = [1,null,8], root2 = [8,1]
 * Output: [1,1,8,8]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * Each tree has at most 5000 nodes.
 * Each node's value is between [-10^5, 10^5].
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
    }
    int peak() {
        return s.top()->val;
    }
    int next() {
        if(!hasNext()) return -1;
        auto t = s.top(); s.pop();
        int res = t->val;
        t = t->right;
        while(t) {
            s.push(t);
            t = t->left;
        }
        return res;
    }
    bool hasNext() {
        return !s.empty();
    }
private:
    stack<TreeNode*> s;
};
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        BSTIterator it1(root1), it2(root2);
        vector<int> res;
        while(it1.hasNext() && it2.hasNext()) {
            int v1 = it1.peak(), v2 = it2.peak();
            if(v1 == v2) {
                res.push_back(v1);
                res.push_back(v2);
                it1.next(); it2.next();
            } else if(v1 < v2) {
                res.push_back(v1);
                it1.next();
            } else {
                res.push_back(v2);
                it2.next();
            }
        }
        while(it1.hasNext()) res.push_back(it1.next());
        while(it2.hasNext()) res.push_back(it2.next());
        return res;
    }
};
// @lc code=end

