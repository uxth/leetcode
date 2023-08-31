/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (48.17%)
 * Likes:    839
 * Dislikes: 348
 * Total Accepted:    90.3K
 * Total Submissions: 186.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * Output:  [1,2,4,7,5,3,6,8,9]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        unordered_map<int, vector<int>> m;
        int maxkey=0;
        for(int i=matrix.size()-1; i>=0; --i)
        {
            for(int j=0; j<matrix[i].size(); ++j)
            {
                m[i+j].push_back(matrix[i][j]);
                maxkey=max(maxkey, i+j);
            }
        }
        vector<int> res;
        for(int k=0; k<=maxkey; ++k) 
        {
            if(k%2) res.insert(res.end(), m[k].rbegin(), m[k].rend());
            else res.insert(res.end(), m[k].begin(), m[k].end());
        }
        return res;
    }
};
// @lc code=end

