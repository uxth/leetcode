/*
 * @lc app=leetcode id=1219 lang=cpp
 *
 * [1219] Path with Maximum Gold
 */

// @lc code=start
class Solution {
public:
    int m, n;
    vector<pair<int,int>> dir{{-1,0}, {1,0}, {0,-1}, {0,1}};
    int dfs(vector<vector<int>>& grid, int y, int x){
        if(y<0||x<0||y>=m||x>=n||grid[y][x]==0) return 0;
        int res = 0;
        int ori = grid[y][x];
        grid[y][x] = 0;
        for(auto& d : dir) res = max(res, dfs(grid, y+d.first, x+d.second));
        grid[y][x] = ori;
        return res + grid[y][x];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int res = 0;
        for(int i=0; i<m; ++i) for(int j=0; j<n; ++j)
            if(grid[i][j])
                res = max(res, dfs(grid, i, j));
        
        return res;
    }
};
// @lc code=end

