/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (46.57%)
 * Likes:    2090
 * Dislikes: 78
 * Total Accepted:    211.5K
 * Total Submissions: 450K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dir{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    bool check(vector<string>& path, int y, int x)
    {
        int n = path.size();
        for(auto& d : dir)
        {
            int i=y; int j=x;
            while(i>=0&&j>=0&&i<n&&j<n)
            {
                if(path[i][j] == 'Q') return false;
                i+=d[0];
                j+=d[1];
            }
        }
        return true;
    }
    void dfs(int n, int i, vector<string>& path, vector<vector<string>>& res)
    {
        if(i==n)
        {
            res.push_back(path);
            return ;
        }

        for(int j=0;j<n;++j)
        {
            if(!check(path, i, j)) continue;
            path[i][j] = 'Q';
            dfs(n, i+1, path, res);
            path[i][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));
        dfs(n, 0, path, res);
        return res;
    }
};
// @lc code=end

