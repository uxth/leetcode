/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (58.82%)
 * Likes:    784
 * Dislikes: 140
 * Total Accepted:    79.8K
 * Total Submissions: 135.5K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
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
class Solution {
public:
    int dfs(TreeNode* root, unordered_map<int,int>& m)
    {
        if(root==nullptr) return 0;
        int res = root->val;
        res += dfs(root->left, m) + dfs(root->right, m);
        m[res]++;
        return res;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == nullptr) return {};
        unordered_map<int,int> m;
        dfs(root, m);
        vector<pair<int,int>> d(m.begin(), m.end());
        sort(d.begin(), d.end(), [](auto& a, auto& b){return a.second > b.second;});
        int freq = d[0].second;
        int i=0;
        vector<int> res;
        while(i<d.size() && d[i].second == freq){res.push_back(d[i++].first);}
        return res;
    }
};
// @lc code=end
// [5,2,-5]
