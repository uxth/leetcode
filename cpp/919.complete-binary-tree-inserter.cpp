/*
 * @lc app=leetcode id=919 lang=cpp
 *
 * [919] Complete Binary Tree Inserter
 *
 * https://leetcode.com/problems/complete-binary-tree-inserter/description/
 *
 * algorithms
 * Medium (57.30%)
 * Likes:    302
 * Dislikes: 51
 * Total Accepted:    17.1K
 * Total Submissions: 29.7K
 * Testcase Example:  '["CBTInserter","insert","get_root"]\n[[[1]],[2],[]]'
 *
 * A complete binary tree is a binary tree in which every level, except
 * possibly the last, is completely filled, and all nodes are as far left as
 * possible.
 * 
 * Write a data structure CBTInserter that is initialized with a complete
 * binary tree and supports the following operations:
 * 
 * 
 * CBTInserter(TreeNode root) initializes the data structure on a given tree
 * with head node root;
 * CBTInserter.insert(int v) will insert a TreeNode into the tree with value
 * node.val = v so that the tree remains complete, and returns the value of the
 * parent of the inserted TreeNode;
 * CBTInserter.get_root() will return the head node of the tree.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
 * Output: [null,1,[1,2]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs =
 * [[[1,2,3,4,5,6]],[7],[8],[]]
 * Output: [null,3,4,[1,2,3,4,5,6,7,8]]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The initial given tree is complete and contains between 1 and 1000
 * nodes.
 * CBTInserter.insert is called at most 10000 times per test case.
 * Every value of a given or inserted node is between 0 and 5000.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
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
class CBTInserter {
private:
    vector<TreeNode*> data;
public:

    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* f = q.front();
            q.pop();
            data.push_back(f);
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
    }
    
    int insert(int v) {
        TreeNode* parent = data[(data.size()-1)/2];
        data.push_back(new TreeNode(v));
        
        if(parent->left == nullptr) parent->left=data.back();
        else parent->right = data.back();

        return parent->val;
    }
    
    TreeNode* get_root() {
        return data.front();
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
// ["CBTInserter","insert","insert","get_root"]\n[[[1,2,3,4,5,6]],[7],[8],[]]
