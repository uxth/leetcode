/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 *
 * https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
 *
 * algorithms
 * Easy (76.62%)
 * Likes:    482
 * Dislikes: 30
 * Total Accepted:    61.1K
 * Total Submissions: 79.8K
 * Testcase Example:  '[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]'
 *
 * Given a m * n matrix grid which is sorted in non-increasing order both
 * row-wise and column-wise. 
 * 
 * Return the number of negative numbers in grid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
 * Output: 8
 * Explanation: There are 8 negatives number in the matrix.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[3,2],[1,0]]
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,-1],[-1,-1]]
 * Output: 3
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: grid = [[-1]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 100
 * -100 <= grid[i][j] <= 100
 * 
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int m(grid.size()), n(grid[0].size()), r(0), c(n - 1);
        while (r < m) {
            while (c >= 0 && grid[r][c] < 0) c--;
            res += n - c - 1;
            r++;
        }
        return res;
    }
};
// @lc code=end
/*
[[4,3,2,-1]
,[3,2,1,-1]
,[1,1,-1,-2]
,[-1,-1,-2,-3]]

=======
[[5,1,0],[-5,-5,-5]]


========
[[3,-1,-3,-3,-3]
,[2,-2,-3,-3,-3]
,[1,-2,-3,-3,-3]
,[0,-3,-3,-3,-3]]
*/
