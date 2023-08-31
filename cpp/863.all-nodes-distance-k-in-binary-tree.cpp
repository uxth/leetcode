/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (55.34%)
 * Likes:    2451
 * Dislikes: 50
 * Total Accepted:    89.3K
 * Total Submissions: 159.6K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 * 
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
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
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * 
 * Output: [7,4,1]
 * 
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * 
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these
 * objects.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == nullptr) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* f = q.front(); q.pop();
            if(f->left){parent[f->left]=f; q.push(f->left);}
            if(f->right){parent[f->right]=f;q.push(f->right);}
        }
        q.push(target);
        vector<int> res;
        unordered_set<TreeNode*> visited{target};
        while(K--)
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* f = q.front(); q.pop();
                if(f->left && visited.count(f->left) == 0) {q.push(f->left);visited.insert(f->left);}
                if(f->right && visited.count(f->right) == 0) {q.push(f->right);visited.insert(f->right);}
                if(parent.count(f) && visited.count(parent[f]) == 0) {q.push(parent[f]);visited.insert(parent[f]);}
            }
        }
        while(!q.empty()){res.push_back(q.front()->val); q.pop();}
        return res;
    }
};
// @lc code=end

