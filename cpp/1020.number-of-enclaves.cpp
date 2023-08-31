/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (57.69%)
 * Likes:    333
 * Dislikes: 18
 * Total Accepted:    19.8K
 * Total Submissions: 34.2K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * Given a 2D array A, each cell is 0 (representing sea) or 1 (representing
 * land)
 * 
 * A move consists of walking from one land square 4-directionally to another
 * land square, or off the boundary of the grid.
 * 
 * Return the number of land squares in the grid for which we cannot walk off
 * the boundary of the grid in any number of moves.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: 
 * There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed
 * because its on the boundary.
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: 
 * All 1s are either on the boundary or can reach the boundary.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 500
 * 1 <= A[i].length <= 500
 * 0 <= A[i][j] <= 1
 * All rows have the same size.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    int paint(vector<vector<int>>& A, int y, int x, int marker)
    {
        int m = A.size(); 
        int n = A[0].size();

        queue<pair<int,int>> q;
        q.push({y,x});
        int res = 0;
        while(!q.empty())
        {
            int fy = q.front().first;
            int fx = q.front().second;
            q.pop();
            if(fy<0||fx<0||fy>=m||fx>=n) continue;
            if(A[fy][fx]!=1) continue;
            A[fy][fx] = marker;
            res++;
            for(auto& d : dir)
            {
                q.push({fy+d.first, fx+d.second});
            }
        }
        return res;
    }
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size(); 
        int n = A[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; ++i)
        {
            if(A[i][0] == 1) paint(A, i, 0, 0);
            if(A[i][n-1] == 1) paint(A, i, n-1, 0);
        }
        for(int j=0; j<n; ++j)
        {
            if(A[0][j] == 1) paint(A, 0, j, 0);
            if(A[m-1][j] == 1) paint(A, m-1, j, 0);
        }
        int res = 0;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(A[i][j] == 1)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

