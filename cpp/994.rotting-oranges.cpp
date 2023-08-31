/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (47.76%)
 * Likes:    2574
 * Dislikes: 199
 * Total Accepted:    166.9K
 * Total Submissions: 337.9K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * In a given grid, each cell can have one of three values:
 * 
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is adjacent (4-directionally) to a
 * rotten orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange.  If this is impossible, return -1 instead.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation:  The orange in the bottom left corner (row 2, column 0) is
 * never rotten, because rotting only happens 4-directionally.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] is only 0, 1, or 2.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0; i<m; ++i) for(int j=0; j<n; ++j)
        {
            if(grid[i][j] == 1) fresh++;
            else if(grid[i][j] == 2) q.push({i,j});
        }
        int res = 0;
        if(fresh == 0) return 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(auto& [dy, dx] : dir)
                {
                    int ny=dy+y; int nx=dx+x;
                    if(ny<0||nx<0||ny>=m||nx>=n||grid[ny][nx]!=1) continue;
                    grid[ny][nx] = 2;
                    q.push({ny,nx});
                    fresh--;
                }
            }
            res++;
        }
        return fresh == 0 ? res-1 : -1;
    }
};
// @lc code=end

