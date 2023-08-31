/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
 *
 * https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
 *
 * algorithms
 * Medium (53.33%)
 * Likes:    349
 * Dislikes: 6
 * Total Accepted:    9.7K
 * Total Submissions: 18.1K
 * Testcase Example:  '[1,2,3,null,4]\n3'
 *
 * Given the root of a binary tree and an integer distance. A pair of two
 * different leaf nodes of a binary tree is said to be good if the length of
 * the shortest path between them is less than or equal to distance.
 * 
 * Return the number of good leaf node pairs in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,4], distance = 3
 * Output: 1
 * Explanation: The leaf nodes of the tree are 3 and 4 and the length of the
 * shortest path between them is 3. This is the only good pair.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3,4,5,6,7], distance = 3
 * Output: 2
 * Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The
 * pair [4,6] is not good because the length of ther shortest path between them
 * is 4.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
 * Output: 1
 * Explanation: The only good pair is [2,5].
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [100], distance = 1
 * Output: 0
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [1,1,1], distance = 2
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 2^10].
 * Each node's value is between [1, 100].
 * 1 <= distance <= 10
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
    // unordered_map<TreeNode*, vector<int>> dis;
    // void countdis(TreeNode* root)
    // {
    //     if(root == nullptr) return;
    //     if(dis.count(root)) return;
    //     if(root->left == nullptr && root->right == nullptr)
    //     {
    //         dis[root].push_back(0);
    //         return;
    //     }
    //     countdis(root->left); 
    //     countdis(root->right);
    //     vector<int> tmp;
    //     if(root->left) tmp.insert(tmp.end(), dis[root->left].begin(), dis[root->left].end());
    //     if(root->right) tmp.insert(tmp.end(), dis[root->right].begin(), dis[root->right].end());
    //     for(int i=0; i<tmp.size(); ++i)
    //         tmp[i]++;
    //     dis[root] = tmp;
    // }
    // int countPairs(TreeNode* root, int distance) {
    //     if(root == nullptr) return 0;
    //     countdis(root);
    //     int res = 0;

    //     if(root->left && root->right)
    //     {
    //         for(int l : dis[root->left])
    //             for(int r : dis[root->right])
    //                 res += l+r+1 < distance;
    //     }
    //     return res + countPairs(root->left, distance) + countPairs(root->right, distance);
    // }


    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, ans, distance);
        return ans;
    }
    
    vector<int> dfs(TreeNode *root, int& ans, int &distance) {
        vector<int> dist(distance+1, 0);
        if (!root) return dist;
        if (!root->left && !root->right) {
            dist[1] = 1;
            return dist;
        }
        vector<int> leftDist = dfs(root->left, ans, distance);
        vector<int> rightDist = dfs(root->right, ans, distance);
        
        for (int i = 0; i < leftDist.size(); i++) {
            for (int j = 0; j < rightDist.size(); j++) {
                if (i + j <= distance) {
                    ans += leftDist[i] * rightDist[j];
                }
            }
        }
        
        for (int i = 1; i <= distance; i++) {
            dist[i] = leftDist[i-1] + rightDist[i-1];
        }
        
        return dist;
    }
};
// @lc code=end
// [15,66,55,97,60,12,56,null,54,null,49,null,9,null,null,null,null,null,90]\n5
