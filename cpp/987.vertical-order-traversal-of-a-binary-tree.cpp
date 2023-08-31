/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 *
 * https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (36.02%)
 * Likes:    954
 * Dislikes: 1961
 * Total Accepted:    96.6K
 * Total Submissions: 261.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the vertical order traversal of its nodes
 * values.
 * 
 * For each node at position (X, Y), its left and right children respectively
 * will be at positions (X-1, Y-1) and (X+1, Y-1).
 * 
 * Running a vertical line from X = -infinity to X = +infinity, whenever the
 * vertical line touches some nodes, we report the values of the nodes in order
 * from top to bottom (decreasing Y coordinates).
 * 
 * If two nodes have the same position, then the value of the node that is
 * reported first is the value that is smaller.
 * 
 * Return an list of non-empty reports in order of X coordinate.  Every report
 * will have a list of values of nodes.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * 
 * Input: [3,9,20,null,null,15,7]
 * Output: [[9],[3,15],[20],[7]]
 * Explanation: 
 * Without loss of generality, we can assume the root node is at position (0,
 * 0):
 * Then, the node with value 9 occurs at position (-1, -1);
 * The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
 * The node with value 20 occurs at position (1, -1);
 * The node with value 7 occurs at position (2, -2).
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [1,2,3,4,5,6,7]
 * Output: [[4],[2],[1,5,6],[3],[7]]
 * Explanation: 
 * The node with value 5 and the node with value 6 have the same position
 * according to the given scheme.
 * However, in the report "[1,5,6]", the node value of 5 comes first since 5 is
 * smaller than 6.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The tree will have between 1 and 1000 nodes.
 * Each node's value will be between 0 and 1000.
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
class Solution {
public:
    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     if(root == nullptr) return {};
    //     queue<pair<TreeNode*, int>> q;
    //     q.push({root, 0});
    //     map<int, vector<int>> ans;
    //     while(!q.empty())
    //     {
    //         int size = q.size();
    //         unordered_map<int, vector<int>> data;
    //         while(size--)
    //         {
    //             TreeNode* f = q.front().first;
    //             int x = q.front().second;
    //             q.pop();
    //             data[x].push_back(f->val);
    //             if(f->left) q.push({f->left, x-1});
    //             if(f->right) q.push({f->right, x+1});
    //         }
    //         for(auto& [x, list] : data)
    //         {
    //             sort(list.begin(), list.end());
    //             ans[x].insert(ans[x].end(), list.begin(), list.end());
    //         }
    //     }
    //     vector<vector<int>> res;
    //     for(auto& [x, list] : ans)
    //         res.push_back(list);
    //     return res;
    // }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        map<int, map<int, multiset<int>>> ans;
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* f = q.front().first;
                int x = q.front().second;
                q.pop();
                ans[x][level].insert(f->val);
                if(f->left) q.push({f->left, x-1});
                if(f->right) q.push({f->right, x+1});
            }
            level++;
        }
        
        vector<vector<int>> res;
        for(auto& col : ans)
        {
            vector<int> t;
            for(auto& data : col.second)
                t.insert(t.end(), data.second.begin(), data.second.end());
            res.push_back(t);
        }
        return res;
    }


    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     if(root == nullptr) return {};
    //     queue<pair<TreeNode*, int>> q;
    //     q.push({root, 0});
    //     map<int, vector<int>> ans;
    //     while(!q.empty())
    //     {
    //         int size = q.size();
    //         map<int, multiset<int>> data;
    //         while(size--)
    //         {
    //             TreeNode* f = q.front().first;
    //             int x = q.front().second;
    //             q.pop();
    //             data[x].insert(f->val);
    //             if(f->left) q.push({f->left, x-1});
    //             if(f->right) q.push({f->right, x+1});
    //         }
    //         for(auto& d : data)
    //             ans[d.first].insert(ans[d.first].end(), d.second.begin(), d.second.end());
    //     }
        
    //     vector<vector<int>> res;
    //     for(auto& [x,list] : ans)
    //         res.push_back(list);
    //     return res;
    // }
};
// @lc code=end
// [3,1,4,0,2,2]
