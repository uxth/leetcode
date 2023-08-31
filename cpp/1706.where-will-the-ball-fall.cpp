/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 *
 * https://leetcode.com/problems/where-will-the-ball-fall/description/
 *
 * algorithms
 * Medium (53.27%)
 * Likes:    80
 * Dislikes: 12
 * Total Accepted:    3.4K
 * Total Submissions: 6.3K
 * Testcase Example:  '[[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]'
 *
 * You have a 2-D grid of size m x n representing a box, and you have n balls.
 * The box is open on the top and bottom sides.
 * 
 * Each cell in the box has a diagonal board spanning two corners of the cell
 * that can redirect a ball to the right or to the left.
 * 
 * 
 * A board that redirects the ball to the right spans the top-left corner to
 * the bottom-right corner and is represented in the grid as 1.
 * A board that redirects the ball to the left spans the top-right corner to
 * the bottom-left corner and is represented in the grid as -1.
 * 
 * 
 * We drop one ball at the top of each column of the box. Each ball can get
 * stuck in the box or fall out of the bottom. A ball gets stuck if it hits a
 * "V" shaped pattern between two boards or if a board redirects the ball into
 * either wall of the box.
 * 
 * Return an array answer of size n where answer[i] is the column that the ball
 * falls out of at the bottom after dropping the ball from the i^th column at
 * the top, or -1 if the ball gets stuck in the box.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
 * Output: [1,-1,-1,-1,-1]
 * Explanation: This example is shown in the photo.
 * Ball b0 is dropped at column 0 and falls out of the box at column 1.
 * Ball b1 is dropped at column 1 and will get stuck in the box between column
 * 2 and 3 and row 1.
 * Ball b2 is dropped at column 2 and will get stuck on the box between column
 * 2 and 3 and row 0.
 * Ball b3 is dropped at column 3 and will get stuck on the box between column
 * 2 and 3 and row 0.
 * Ball b4 is dropped at column 4 and will get stuck on the box between column
 * 2 and 3 and row 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[-1]]
 * Output: [-1]
 * Explanation: The ball gets stuck against the left wall.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 100
 * grid[i][j] is 1 or -1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>>& g, int i, int j, int b, vector<int>& res)
    {
        if(j<0||j>=g[0].size()||g[i][j]!=0) return false;
        if(i==g.size()-1)
        {
            res[b] = j/3;
            return true;
        }
        g[i][j] = -1;
        
        if(dfs(g, i+1, j, b, res)) {g[i][j] = 0;return true;}
        if(dfs(g, i, j-1, b, res)) {g[i][j] = 0;return true;}
        if(dfs(g, i, j+1, b, res)) {g[i][j] = 0;return true;}
        g[i][j] = 0;
        return false;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> g(3*m, vector<int>(3*n, 0));
        for(int i=0; i<m; ++i) for(int j=0; j<n; ++j)
        {
            if(grid[i][j] == 1)
            {
                g[3*i][3*j] = g[3*i+1][3*j+1] = g[3*i+2][3*j+2] = -1;
            }
            else
            {
                g[3*i][3*j+2] = g[3*i+1][3*j+1] = g[3*i+2][3*j] = -1;
            }
        }
        vector<int> res(n, -1);
        for(int b=0; b<n; ++b)
        {
            dfs(g, 0, 3*b+1, b, res);
        }
        return res;
    }
};
// @lc code=end

