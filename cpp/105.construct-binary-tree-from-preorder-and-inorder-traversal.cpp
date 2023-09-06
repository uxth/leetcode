/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* dfs(vector<int>& preorder, int pre_left, int pre_right,
            vector<int>& inorder, int in_left, int in_right){
        if(preorder.empty() || inorder.empty()) return nullptr;
        if(pre_left > pre_right || in_left > in_right) return nullptr;
        int pivot = in_left;
        while(inorder[pivot] != preorder[pre_left]) pivot++;
        TreeNode* res = new TreeNode(preorder[pre_left]);
        res->left = dfs(preorder, pre_left+1, pre_left+pivot-in_left, inorder, in_left, pivot-1);
        res->right = dfs(preorder, pre_left+pivot-in_left+1, pre_right, inorder, pivot+1, in_right);
        return res;
    }
    TreeNode* bfs(vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty() || inorder.empty()) return nullptr;
        stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i=0, j=0, f=0;
        
        s.push(preorder[i]);
        
        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;
        
        while(i<preorder.size()){
            if(!st.empty() && st.top()->val==inorder[j]){
                t = st.top();
                st.pop();
                s.pop();
                f = 1;
                j++;
            }else{
                if(f==0){
                    s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }else{
                    f = 0;
                    s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bfs(preorder, inorder);
        // return dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
// @lc code=end

