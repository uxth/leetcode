/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (41.12%)
 * Likes:    1325
 * Dislikes: 268
 * Total Accepted:    78.7K
 * Total Submissions: 191.4K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    void mark(vector<vector<int>>& matrix, vector<vector<int>>& dp, queue<pair<int,int>>& q, int marker)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        while(!q.empty())
        {
            auto& f = q.front();
            dp[f.first][f.second] |= marker;
            for(auto& d : dir)
            {
                int y = f.first + d.first;
                int x = f.second + d.second;
                if(y<0||x<0||y>=m||x>=n) continue;
                if(dp[y][x] & marker) continue;
                if(matrix[y][x] >= matrix[f.first][f.second])q.push({y,x});
            }
            q.pop();
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        for(int i=0; i<m; ++i) q.push({i, 0});
        for(int j=0; j<n; ++j) q.push({0, j});
        mark(matrix, dp, q, 1);

        for(int i=0; i<m; ++i) q.push({i, n-1});
        for(int j=0; j<n; ++j) q.push({m-1, j});
        mark(matrix, dp, q, 2);

        vector<vector<int>> res;
        for(int i=0; i<m; ++i)for(int j=0; j<n; ++j)
            if(dp[i][j] == 3) res.push_back({i,j});
        return res;
    }
};
// @lc code=end

