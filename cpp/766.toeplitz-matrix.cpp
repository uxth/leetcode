/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 *
 * https://leetcode.com/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (65.03%)
 * Likes:    1201
 * Dislikes: 84
 * Total Accepted:    110.9K
 * Total Submissions: 169.1K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise,
 * return false.
 * 
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
 * same elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * Output: true
 * Explanation:
 * In the above grid, the diagonals are:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
 * In each diagonal all elements are the same, so the answer is True.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2],[2,2]]
 * Output: false
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 20
 * 0 <= matrix[i][j] <= 99
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the matrix is stored on disk, and the memory is limited such that
 * you can only load at most one row of the matrix into the memory at once?
 * What if the matrix is so large that you can only load up a partial row into
 * the memory at once?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int, unordered_set<int>> data;
        for(int i=0; i<matrix.size(); ++i) for(int j=0; j<matrix[i].size(); ++j)
        {
            data[j-i].insert(matrix[i][j]);
            if(data[j-i].size() > 1) return false;
        }
        return true;
    }
};
// @lc code=end

