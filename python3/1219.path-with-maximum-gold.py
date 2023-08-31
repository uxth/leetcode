#
# @lc app=leetcode id=1219 lang=python3
#
# [1219] Path with Maximum Gold
#

# @lc code=start
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        def dfs(i, j):
            if grid[i][j] == 0:
                return 0
            temp = grid[i][j]
            
            grid[i][j] = 0
            ans = 0
            for ni, nj in (i+1,j), (i,j+1), (i-1,j), (i,j-1):
                if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] > 0:
                    ans = max(ans, dfs(ni, nj))
            grid[i][j] = temp
            
            return ans + temp
        
        res=0
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    res=max(res,dfs(i, j))
        
        return res