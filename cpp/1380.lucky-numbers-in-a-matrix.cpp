/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 *
 * https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
 *
 * algorithms
 * Easy (71.45%)
 * Likes:    264
 * Dislikes: 26
 * Total Accepted:    27.1K
 * Total Submissions: 38K
 * Testcase Example:  '[[3,7,8],[9,11,13],[15,16,17]]'
 *
 * Given a m * n matrix of distinct numbers, return all lucky numbers in the
 * matrix in any order.
 * 
 * A lucky number is an element of the matrix such that it is the minimum
 * element in its row and maximum in its column.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
 * Output: [15]
 * Explanation: 15 is the only lucky number since it is the minimum in its row
 * and the maximum in its column
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
 * Output: [12]
 * Explanation: 12 is the only lucky number since it is the minimum in its row
 * and the maximum in its column.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[7,8],[1,2]]
 * Output: [7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= n, m <= 50
 * 1 <= matrix[i][j] <= 10^5.
 * All elements in the matrix are distinct.
 * 
 */

// @lc code=start
class Solution {
public:
    bool isMaxInCol(vector<vector<int>>& matrix, int y, int x)
    {
        for(int i=0; i<matrix.size(); ++i)
        {
            if(matrix[i][x] > matrix[y][x]) return false;
        }
        return true;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;

        for(int i=0; i<m; ++i)
        {
            int m = INT_MAX;
            int x = -1;
            for(int j=0; j<n; ++j)
            {
                if(m > matrix[i][j])
                {
                    m = matrix[i][j];
                    x = j;
                }
            }

            if(isMaxInCol(matrix, i, x)) res.push_back(matrix[i][x]);
        }

        return res;
    }
};
// @lc code=end

