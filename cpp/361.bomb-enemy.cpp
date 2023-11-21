/*

Question
Formatted question description: https://leetcode.ca/all/361.html

Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.

 

Example 1:



Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
Example 2:



Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 'W', 'E', or '0'.
Algorithm
Create four cumulative arrays v1, v2, v3, v4,

v1 is the cumulative array from left to right in the horizontal direction
v2 is the cumulative array from right to left in the horizontal direction
v3 is the cumulative array from top to bottom in the vertical direction
v4 is the cumulative array from bottom to top in the vertical direction
After building this cumulative array, for any position (i, j), the maximum number of enemies that can be killed is v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j], finally by comparing the cumulative sum of each position, you can get the result.

*/

// OJ: https://leetcode.com/problems/bomb-enemy/
// Time: O(MN(M+N))
// Space: O(1)
class Solution {
private:
    int M, N;
    int dirs[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int count(vector<vector<char>>& grid, int x, int y, int dir[2]) {
        int ans = 0;
        while (true) {
            x += dir[0];
            y += dir[1];
            if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y] == 'W') break;
            if (grid[x][y] == 'E') ++ans;
        }
        return ans;
    }
    int count(vector<vector<char>>& grid, int x, int y) {
        int ans = 0;
        for (auto &dir : dirs) ans += count(grid, x, y, dir);
        return ans;
    }
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        M = grid.size();
        N = grid[0].size();
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != '0') continue;
                ans = max(ans, count(grid, i, j));
            }
        }
        return ans;
    }
};