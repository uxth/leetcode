/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (40.04%)
 * Likes:    1382
 * Dislikes: 203
 * Total Accepted:    143.2K
 * Total Submissions: 353.3K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 * 
 * 
 * 
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 * 
 * 
 * Example:
 * 
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 * 
 * 
 */

// @lc code=start
class NumMatrix {
    private:
	vector<vector<int>> m;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return;
        m = matrix;
        for (int i = 1; i < m.size(); ++i)
            m[i][0] += m[i - 1][0];
        for (int j = 1; j < m[0].size(); ++j)
            m[0][j] += m[0][j - 1];

        for(int i=1; i<m.size(); ++i)
        {
            for(int j=1; j<m[0].size(); ++j)
            {
                m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0)
        {
            return m[row2][col2];
        }
        else if(row1 == 0 && col1 != 0)
        {
            return m[row2][col2] - m[row2][col1 - 1];
        }
        else if(row1 != 0 && col1 == 0)
        {
            return m[row2][col2] - m[row1 - 1][col2];
        }
        else
        {
            return m[row2][col2] - m[row2][col1 - 1] - m[row1 - 1][col2] + m[row1 - 1][col1 - 1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

