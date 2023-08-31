/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (60.32%)
 * Likes:    425
 * Dislikes: 18
 * Total Accepted:    21.4K
 * Total Submissions: 35.3K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 * 
 * Return the number of closed islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation: 
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 * 
 */

// @lc code=start
class Solution {
public:
    int fill(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j])
            return 0;
        return (g[i][j] = 1) + fill(g, i + 1, j) + fill(g, i, j + 1) 
            + fill(g, i - 1, j) + fill(g, i, j - 1);
    }
    int border(vector<vector<int>>& g)
    {    
        for (int i = 0; i < g.size(); ++i)
        {
            fill(g, i, 0);
            fill(g, i, g[0].size()-1);
        }
        for (int j = 0; j < g[0].size(); ++j)
        {
            fill(g, 0, j);
            fill(g, g.size()-1, j);
        }
        int res = 0;
        for (int i = 0; i < g.size(); ++i)
            for (int j = 0; j < g[i].size(); ++j)
                res += fill(g, i, j) > 0;
        return res;

    }
    int closedIsland(vector<vector<int>>& g) {
        // return border(g);
        return dfs(g);
    }
    vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    bool helper(vector<vector<int>>& g, int y, int x)
    {
        if(y<0||x<0||y==g.size()||x==g[0].size()) return true;
        if(g[y][x]==1) return false;
        g[y][x] = 1;
        bool res = false;
        for(auto& d : dir) res |= helper(g, y+d[0], x+d[1]);
        return res;
    }
    int dfs(vector<vector<int>>& g)
    {
        int res = 0;
        for(int i=0; i<g.size(); ++i) for(int j=0;j<g[0].size(); ++j)
        {
            if(g[i][j] == 0 && !helper(g, i, j)) res++;
        }
        return res;
    }
};
// @lc code=end

