/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (28.08%)
 * Likes:    2035
 * Dislikes: 705
 * Total Accepted:    255.5K
 * Total Submissions: 898.5K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    void mark(vector<vector<char>>& board, int y, int x, char ori, char target)
    {
        int m = board.size(); int n = board[0].size();
        if(y<0||x<0||y>=m||x>=n) return;
        if(board[y][x] != ori) return;
        board[y][x] = target;
        for(auto& d : dir) mark(board, y+d.first, x+d.second, ori, target);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return ;
        int m = board.size(); int n = board[0].size();
        for(int i=0;i<m;++i){mark(board, i, 0, 'O', '=');mark(board, i, n-1, 'O', '=');}
        for(int j=0;j<n;++j){mark(board, 0, j, 'O', '=');mark(board, m-1, j, 'O', '=');}
        for(int i=0;i<m;++i) for(int j=0;j<n;++j)
            if(board[i][j] == 'O') board[i][j] = 'X';

        for(int i=0;i<m;++i){mark(board, i, 0, '=', 'O');mark(board, i, n-1, '=', 'O');}
        for(int j=0;j<n;++j){mark(board, 0, j, '=', 'O');mark(board, m-1, j, '=', 'O');}
    }
};
// @lc code=end

