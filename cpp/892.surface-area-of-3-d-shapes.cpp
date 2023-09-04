/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start
class Solution {
public:

    int surfaceArea(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        auto surface = [](int size){
            if(size == 0) return 0;
            return size*4+2;
        };
        int res = surface(grid[0][0]);
        for(int j=1; j<n; ++j)
            res += surface(grid[0][j]) - min(grid[0][j], grid[0][j-1]) * 2;
        for(int i=1; i<n; ++i)
            res += surface(grid[i][0]) - min(grid[i][0], grid[i-1][0]) * 2;
        for(int i=1; i<n; ++i) for(int j=1; j<n; ++j)
            res += surface(grid[i][j]) - min(grid[i][j], grid[i-1][j]) * 2 - min(grid[i][j], grid[i][j-1]) * 2;
        return res;

    }
};
// @lc code=end

