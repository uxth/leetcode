/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (52.41%)
 * Likes:    1593
 * Dislikes: 116
 * Total Accepted:    393.3K
 * Total Submissions: 748.7K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; ++i)
        {
            vector<int> tmp(i+1);
            for(int j=0; j<=i; ++j)
            {
                tmp[j] = j==0 || j==i ? 1 : res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

