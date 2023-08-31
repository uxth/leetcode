/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (43.42%)
 * Likes:    483
 * Dislikes: 27
 * Total Accepted:    20.2K
 * Total Submissions: 46.5K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an N x N grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized and return the distance.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * If no land or water exists in the grid, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: 
 * The cell (1, 1) is as far as possible from all the land with distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: 
 * The cell (2, 2) is as far as possible from all the land with distance
 * 4.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        int count  = 0;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 1) 
                {
                    visited[i][j] = true;
                    q.push({i,j});
                    count++;
                }
            }
        }
        if(count == m*n) return -1;
        int step = 0;
        while(!q.empty())
        {
            
            int size = q.size();
            while(size--)
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(auto& d : dir)
                {
                    int i = y+d.first;
                    int j = x+d.second;
                    if(i<0||j<0||i>=m||j>=n||visited[i][j]) continue;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
            step++;
        }
        return step-1;
    }
};
// @lc code=end
// [[1,1,1,1,1],[1,1,1,1,1],[1,1,1,1,1],[1,1,1,1,1],[1,1,1,1,1]]
// [[1,0,1],[0,0,0],[1,0,1]]
