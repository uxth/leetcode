/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
 *
 * https://leetcode.com/problems/print-binary-tree/description/
 *
 * algorithms
 * Medium (54.96%)
 * Likes:    348
 * Dislikes: 834
 * Total Accepted:    32.8K
 * Total Submissions: 59.7K
 * Testcase Example:  '[1,2]'
 *
 * Print a binary tree in an m*n 2D string array following these rules: 
 * 
 * 
 * The row number m should be equal to the height of the given binary tree.
 * The column number n should always be an odd number.
 * The root node's value (in string format) should be put in the exactly middle
 * of the first row it can be put. The column and the row where the root node
 * belongs will separate the rest space into two parts (left-bottom part and
 * right-bottom part). You should print the left subtree in the left-bottom
 * part and print the right subtree in the right-bottom part. The left-bottom
 * part and the right-bottom part should have the same size. Even if one
 * subtree is none while the other is not, you don't need to print anything for
 * the none subtree but still need to leave the space as large as that for the
 * other subtree. However, if two subtrees are none, then you don't need to
 * leave space for both of them. 
 * Each unused space should contain an empty string "".
 * Print the subtrees following the same rules.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * ⁠    1
 * ⁠   /
 * ⁠  2
 * Output:
 * [["", "1", ""],
 * ⁠["2", "", ""]]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * ⁠    1
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \
 * ⁠    4
 * Output:
 * [["", "", "", "1", "", "", ""],
 * ⁠["", "2", "", "", "", "3", ""],
 * ⁠["", "", "4", "", "", "", ""]]
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * ⁠     1
 * ⁠    / \
 * ⁠   2   5
 * ⁠  / 
 * ⁠ 3 
 * ⁠/ 
 * 4 
 * Output:
 * 
 * [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 * ⁠["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 * ⁠["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 * ⁠["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 * 
 * 
 * 
 * Note:
 * The height of binary tree is in the range of [1, 10].
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
    void fillTable(vector<vector<string>>& res, TreeNode* root, int level, int start, int end)
    {
        if(root == nullptr) return;
        int mid = (end+start)/2;
        res[level][mid] = to_string(root->val);
        fillTable(res, root->left, level+1, start, mid-1);
        fillTable(res, root->right, level+1, mid+1, end);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q; q.push(root);
        int depth=0;
        while(!q.empty())
        {
            int size = q.size();
            depth++;
            while(size--)
            {
                TreeNode* f = q.front(); q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        int width = (1<<depth) - 1;

        vector<vector<string>> res(depth, vector<string>(width, ""));

        fillTable(res, root, 0, 0, width-1);
        return res;
    }
};
// @lc code=end

