/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 *
 * https://leetcode.com/problems/valid-tic-tac-toe-state/description/
 *
 * algorithms
 * Medium (32.62%)
 * Likes:    221
 * Dislikes: 645
 * Total Accepted:    27.1K
 * Total Submissions: 82.7K
 * Testcase Example:  '["O  ","   ","   "]'
 *
 * A Tic-Tac-Toe board is given as a string array board. Return True if and
 * only if it is possible to reach this board position during the course of a
 * valid tic-tac-toe game.
 * 
 * The board is a 3 x 3 array, and consists of characters " ", "X", and "O".
 * The " " character represents an empty square.
 * 
 * Here are the rules of Tic-Tac-Toe:
 * 
 * 
 * Players take turns placing characters into empty squares (" ").
 * The first player always places "X" characters, while the second player
 * always places "O" characters.
 * "X" and "O" characters are always placed into empty squares, never filled
 * ones.
 * The game ends when there are 3 of the same (non-empty) character filling any
 * row, column, or diagonal.
 * The game also ends if all squares are non-empty.
 * No more moves can be played if the game is over.
 * 
 * 
 * 
 * Example 1:
 * Input: board = ["O  ", "   ", "   "]
 * Output: false
 * Explanation: The first player always plays "X".
 * 
 * Example 2:
 * Input: board = ["XOX", " X ", "   "]
 * Output: false
 * Explanation: Players take turns making moves.
 * 
 * Example 3:
 * Input: board = ["XXX", "   ", "OOO"]
 * Output: false
 * 
 * Example 4:
 * Input: board = ["XOX", "O O", "XOX"]
 * Output: true
 * 
 * 
 * Note:
 * 
 * 
 * board is a length-3 array of strings, where each string board[i] has length
 * 3.
 * Each board[i][j] is a character in the set {" ", "X", "O"}.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nx, no;
    bool xwin, owin;
public:
    Solution() : nx(0), no(0), xwin(false), owin(false)
    {}
    
    bool validTicTacToe(vector<string>& board) 
    {
        for(int i = 0; i < 3; i++)
        {
            for(auto c : board[i])
            {
                if(c == 'X') nx++;
                else if(c == 'O') no++;
            }
        }
        if(!(nx == no || nx == no + 1)) return false;
        else if(nx == no)
        {
            return !isWin(board, 'X');
        }
        else
        {
            return !isWin(board, 'O');
        }
        return true;
    }
    
    bool isWin(vector<string> &board, char c)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][0] == c && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                return true;
            }
            else if(board[0][i] == c && (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            {
                return true;
            }
        }
        if(board[0][0] == c && board[1][1] == board[0][0] && board[2][2] == board[0][0])
        {
            return true;
        }
        else if(board[0][2] == c && board[1][1] == board[0][2] && board[2][0] == board[0][2])
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

