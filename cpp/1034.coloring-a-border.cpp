/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 *
 * https://leetcode.com/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (44.70%)
 * Likes:    133
 * Dislikes: 265
 * Total Accepted:    10.9K
 * Total Submissions: 24.2K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * Given a 2-dimensional grid of integers, each value in the grid represents
 * the color of the grid square at that location.
 * 
 * Two squares belong to the same connected component if and only if they have
 * the same color and are next to each other in any of the 4 directions.
 * 
 * The border of a connected component is all the squares in the connected
 * component that are either 4-directionally adjacent to a square not in the
 * component, or on the boundary of the grid (the first or last row or
 * column).
 * 
 * Given a square at location (r0, c0) in the grid and a color, color the
 * border of the connected component of that square with the given color, and
 * return the final grid.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
 * Output: [[3, 3], [3, 2]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
 * Output: [[1, 3, 3], [2, 3, 3]]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
 * Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 50
 * 1 <= grid[0].length <= 50
 * 1 <= grid[i][j] <= 1000
 * 0 <= r0 < grid.length
 * 0 <= c0 < grid[0].length
 * 1 <= color <= 1000
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    // void paint(vector<vector<int>>& grid, int y, int x, int oldcolor, int newcolor)
    // {
    //     if(y<0||x<0||y>=grid.size()||x>=grid[0].size()) return;
    //     if(grid[y][x] != oldcolor) return;
    //     grid[y][x] = newcolor;
    //     for(auto& d : dir) paint(grid, y+d[0], x+d[1], oldcolor, newcolor);
    // }
    // vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    //     int oldcolor = grid[r0][c0];
    //     paint(grid, r0, c0, oldcolor, -oldcolor);
    //     for(int i=1; i<grid.size()-1; ++i) for(int j=1; j<grid[0].size()-1; ++j)
    //     {
    //         if(abs(grid[i][j]) == oldcolor 
    //         && abs(grid[i-1][j]) == oldcolor
    //         && abs(grid[i+1][j]) == oldcolor
    //         && abs(grid[i][j-1]) == oldcolor
    //         && abs(grid[i][j+1]) == oldcolor)
    //             grid[i][j] = oldcolor;
    //     }
    //     for (auto i = 0; i < grid.size(); ++i) for (auto j = 0; j < grid[i].size(); ++j)
    //         grid[i][j] = grid[i][j] < 0 ? color : grid[i][j];
    //     return grid;
    // }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        // check whether the position given is valid for the grid
        if(grid[r0][c0] == color) return grid;
        int value = grid[r0][c0];
        int rows = grid.size();
        int cols = grid[0].size();
        
        dfs(grid, r0, c0, color, value);
        
        for(int i = 0; i  < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                grid[i][j] = abs(grid[i][j]);
            }
        }

        return grid;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int color, int value) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != value) return;
        grid[i][j] = -value;
        if((i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1)||(i>0 && i<grid.size()-1 && j>0 && j<grid[0].size()-1 &&
            (  (abs(grid[i-1][j]) != value && grid[i-1][j] != -color)
            || (abs(grid[i+1][j]) != value && grid[i+1][j] != -color)
            || (abs(grid[i][j-1]) != value && grid[i][j-1] != -color)
            || (abs(grid[i][j+1]) != value && grid[i][j+1] != -color))))
            grid[i][j] = -color;

        dfs(grid, i + 1, j, color, value);
        dfs(grid, i - 1, j, color, value);
        dfs(grid, i, j + 1, color, value);
        dfs(grid, i, j - 1, color, value);
    }

};
// @lc code=end
// [[1,2,2],[2,3,2]]\n0\n1\n3
// [[1,1,1],[1,1,1],[1,1,1]]\n1\n1\n2
// [[1,2,1,2,1,2],[2,2,2,2,1,2],[1,2,2,2,1,2]]\n1\n3\n1
/*
[[2,1,3,2,1,1,2]
,[1,2,3,1,2,1,2]
,[1,2,1,2,2,2,2]
,[2,1,2,2,2,2,2]
,[2,3,3,3,2,1,2]]\n4\n4\n3


*/