/*
 * @lc app=leetcode id=1139 lang=cpp
 *
 * [1139] Largest 1-Bordered Square
 *
 * https://leetcode.com/problems/largest-1-bordered-square/description/
 *
 * algorithms
 * Medium (47.49%)
 * Likes:    226
 * Dislikes: 51
 * Total Accepted:    10.7K
 * Total Submissions: 22.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D grid of 0s and 1s, return the number of elements in the largest
 * square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't
 * exist in the grid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,1,0,0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length <= 100
 * 1 <= grid[0].length <= 100
 * grid[i][j] is 0 or 1
 * 
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int left, int right, int top, int bottom)
    {
        if(left == right && top == bottom) return grid[top][left];
        if(left == right)
        {
            int res = 0;
            for(int i=top; i<=bottom; ++i) res=max(res, grid[i][left]);
            return res;
        }
        if(top == bottom)
        {
            int res = 0;
            for(int j=left; j<=right; ++j) res=max(res, grid[top][j]);
            return res;
        }

        int l=0; int r=0; int t=0; int b=0;
        for(int i=top; i<=bottom; ++i)
        {
            l += grid[i][left];
            r += grid[i][right];
        }
        for(int j=left; j<=right; ++j)
        {
            t += grid[top][j];
            b += grid[bottom][j];
        }
        int target = max(right-left+1, bottom-top+1);
        if(l==target && r==target && t==target && b==target) return target*target;

        return max({dfs(grid, left, right-1, top, bottom), dfs(grid, left+1, right, top, bottom), dfs(grid, left, right, top+1, bottom), dfs(grid, left, right, top, bottom-1)});
    }
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int max = 0; int m = grid.size() , n = grid[0].size();
        vector<vector<int>> hor(m,vector<int> (n,0)) , ver(m,vector<int> (n,0));
    
        for (int i=0; i<m; i++) { 
            for (int j=0; j<n; j++) { 
                if (grid[i][j] == 1) 
                { 
                    hor[i][j] = (j==0)? 1: hor[i][j-1] + 1;   // auxillary horizontal array
                    ver[i][j] = (i==0)? 1: ver[i-1][j] + 1;  // auxillary vertical array
                } 
            } 
        } 
            
        for (int i = m-1; i>=0; i--) { 
            for (int j = n-1; j>=0; j--) { 
                int small = min(hor[i][j], ver[i][j]);  // choose smallest of horizontal and vertical value
                while (small > max) { 
                    if (ver[i][j-small+1] >= small &&  hor[i-small+1][j] >= small)  // check if square exists with 'small' length
                        max = small; 
                    small--; 
                } 
            } 
        } 
        return max*max; 
    }
};
// @lc code=end
/*
[[1,1,1,0]
,[1,0,1,0]
,[1,1,1,1]
,[0,1,0,1]]


[[1,1,1,1]
,[1,0,1,1]
,[1,1,1,1]
,[1,1,1,1]]

[[0,0,1,0]]

[[1,1,0]
,[1,1,1]
,[1,1,1]
,[1,1,1]]

[[1,1,0]
,[1,1,1]
,[1,1,1]
,[0,1,0]
,[1,1,1]
,[0,1,1]
,[1,1,1]]


[[1,0,1,1,1,1,1,1]
,[0,0,1,1,0,1,1,0]
,[0,1,1,0,0,1,1,0]
,[1,0,1,0,1,1,1,1]
,[1,1,1,1,1,1,0,1]
,[0,1,1,1,1,1,1,0]
,[0,1,1,1,1,1,1,1]]
*/
