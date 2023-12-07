/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 *
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
 *
 * algorithms
 * Hard (42.74%)
 * Likes:    547
 * Dislikes: 8
 * Total Accepted:    18.4K
 * Total Submissions: 42.9K
 * Testcase Example:  '[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]\n1'
 *
 * Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In
 * one step, you can move up, down, left or right from and to an empty cell.
 * 
 * Return the minimum number of steps to walk from the upper left corner (0, 0)
 * to the lower right corner (m-1, n-1) given that you can eliminate at most k
 * obstacles. If it is not possible to find such walk return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * grid = 
 * [[0,0,0],
 * [1,1,0],
 * ⁠[0,0,0],
 * [0,1,1],
 * ⁠[0,0,0]], 
 * k = 1
 * Output: 6
 * Explanation: 
 * The shortest path without eliminating any obstacle is 10. 
 * The shortest path with one obstacle elimination at position (3,2) is 6. Such
 * path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * grid = 
 * [[0,1,1],
 * [1,1,1],
 * [1,0,0]], 
 * k = 1
 * Output: -1
 * Explanation: 
 * We need to eliminate at least two obstacles to find such a walk.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * grid.length == m
 * grid[0].length == n
 * 1 <= m, n <= 40
 * 1 <= k <= m*n
 * grid[i][j] == 0 or 1
 * grid[0][0] == grid[m-1][n-1] == 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dirs[] = {0, 1, 0, -1, 0};
        int rows = grid.size(), cols = grid[0].size();
        if(k >= rows + cols - 2) return rows + cols - 2;
        vector<vector<vector<bool>>> visited(vector<vector<vector<bool>>>(rows, vector<vector<bool>>(cols, vector<bool> (k + 1))));
        queue<vector<int>> q;
        q.push({0, 0, k, 0});
        visited[0][0][k] = true;
        while(!q.empty()){
            vector<int> top = q.front();
            q.pop();
            int r = top[0], c = top[1], currK = top[2], dist = top[3];
            if(r == rows - 1 && c == cols - 1) return dist;
            for(int i = 0; i < 4; ++i){
                int nr = r + dirs[i], nc = c + dirs[i + 1];
                if(nr < 0 || nr == rows || nc < 0 || nc == cols) continue;
                int newK = currK - grid[nr][nc];
                while(newK >= 0 && !visited[nr][nc][newK]){
                    visited[nr][nc][newK] = true;
                    q.push({nr, nc, newK, dist + 1});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

