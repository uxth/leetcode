/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (46.76%)
 * Likes:    6061
 * Dislikes: 203
 * Total Accepted:    776.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct UnionFind
    {
        vector<int> data;
        int size;
        UnionFind(int n){data.assign(n, -1); size = n;}
        int find(int x)
        {
            if(data[x] == -1) return x;
            data[x] = find(data[x]);
            return data[x];
        }
        void join(int i, int j)
        {
            int ri = find(i);
            int rj = find(j);
            if(ri!=rj)
            {
                data[rj] = ri;
                size--;
            }
        }
        void erase(int x)
        {
            data[x] = INT_MAX;
            size--;
        }
        int count()
        {
            return size;
        }
    };
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m*n);
        if(grid[0][0] == '0') uf.erase(0); 
        for(int i=1; i<m; ++i)
        {
            if(grid[i][0] == '1')
            {
                if(grid[i-1][0] == '1')
                    uf.join((i-1)*n, i*n);
            }
            else
            {
                uf.erase(i*n);
            }
        }
        for(int j=1; j<n; ++j)
        {

            if(grid[0][j] == '1')
            {
                if(grid[0][j-1] == '1')
                    uf.join(j-1, j);
            }
            else
            {
                uf.erase(j);
            }
        }
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    if(grid[i-1][j] == '1') uf.join((i-1)*n+j, i*n+j);
                    if(grid[i][j-1] == '1') uf.join(i*n+j-1, i*n+j);
                }
                else
                {
                    uf.erase(i*n+j);
                }
            }
        }
        
        return uf.count();
    }
};
// @lc code=end
/*
[
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]


[["1","0","1","1","0","1","1"]]
*/
