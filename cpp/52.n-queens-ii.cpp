/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (57.79%)
 * Likes:    595
 * Dislikes: 164
 * Total Accepted:    140.7K
 * Total Submissions: 241K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
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
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));
        dfs(n, 0, path, res);
        return res.size();
    }
};
// @lc code=end

