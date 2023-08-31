/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 *
 * https://leetcode.com/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (73.30%)
 * Likes:    783
 * Dislikes: 74
 * Total Accepted:    38.3K
 * Total Submissions: 51.9K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * On a 2-dimensional grid, there are 4 types of squares:
 * 
 * 
 * 1 represents the starting square.  There is exactly one starting square.
 * 2 represents the ending square.  There is exactly one ending square.
 * 0 represents empty squares we can walk over.
 * -1 represents obstacles that we cannot walk over.
 * 
 * 
 * Return the number of 4-directional walks from the starting square to the
 * ending square, that walk over every non-obstacle square exactly once.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * Output: 2
 * Explanation: We have the following two paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * Output: 4
 * Explanation: We have the following four paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,1],[2,0]]
 * Output: 0
 * Explanation: 
 * There is no path that walks over every empty square exactly once.
 * Note that the starting and ending square can be anywhere in the
 * grid.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length * grid[0].length <= 20
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& grid, int y,int x, int& empty, int& res)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(y<0||x<0||y>=m||x>=n) return;
        if(grid[y][x] < 0) return;
        if(grid[y][x] == 2){
            if(empty == 0) res++;
            return;
        }

        grid[y][x] = -2;
        empty--;
        for(auto& d : dir) dfs(grid, y+d[0], x+d[1], empty, res);
        empty++;
        grid[y][x] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int y0=0; int x0=0;
        int empty = 1;
        for(int i=0;i<m;++i) for(int j=0;j<n;++j)
        {
            if(grid[i][j]==0)empty++;
            else if(grid[i][j]==1){y0=i;x0=j;}
        }
        int res = 0;
        dfs(grid, y0, x0, empty, res);
        return res;
    }
};
// @lc code=end

