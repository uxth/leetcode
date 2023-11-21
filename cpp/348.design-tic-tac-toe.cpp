/*

Question
Formatted question description: https://leetcode.ca/all/348.html

Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that the player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move, and the two players alternate in making moves. Return
0 if there is no winner after the move,
1 if player 1 is the winner after the move, or
2 if player 2 is the winner after the move.
 

Example 1:

Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]

Explanation
TicTacToe ticTacToe = new TicTacToe(3);
Assume that player 1 is "X" and player 2 is "O" in the board.
ticTacToe.move(0, 0, 1); // return 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

ticTacToe.move(0, 2, 2); // return 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

ticTacToe.move(2, 2, 1); // return 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

ticTacToe.move(1, 1, 2); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

ticTacToe.move(2, 0, 1); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

ticTacToe.move(1, 0, 2); // return 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
 

Constraints:

2 <= n <= 100
player is 1 or 2.
0 <= row, col < n
(row, col) are unique for each different call to move.
At most n2 calls will be made to move.
 

Follow-up: Could you do better than O(n2) per move() operation?

Algorithm
The straightforward idea is, to create a board of size nxn, where 0 means that there is no pawn at that position, 1 means that player 1 puts the stone, and 2 means player 2.

Then every time a piece is added to the board, we scan the current row, column, diagonal, and reverse diagonal to see if there are three pieces connected, if there are three pieces, return the corresponding player, if not, return 0.

But, we can do better.

Create a one-dimensional array rows and cols of size n, as well as variable diagonal diag and inverse diagonal rev_diag.

The idea of this method is,

If player 1 puts a child in a certain column of the first row, then rows[0] will increment by 1,
If player 2 puts a child in a certain column of the first row, rows[0] will decrement by 1,
Then only when rows[0] is equal to n or -n, it means that the children in the first row are all placed by a player, and then the game ends and returns to that player. The other rows and columns, the diagonal and the inverse diagonal are all in this way,
*/

// OJ: https://leetcode.com/problems/design-tic-tac-toe/
// Time: O(N)
// Space: O(N^2)
class TicTacToe {
private:
    vector<vector<int>> board;
    int n;
    int status(int row, int col) {
        int p = board[row][col];
        bool win = true;
        for (int i = 0; i < n && win; ++i) {
            if (board[row][i] != p) win = false;
        }
        if (win) return p;
        win = true;
        for (int i = 0; i < n && win; ++i) {
            if (board[i][col] != p) win = false;
        }
        if (win) return p;
        if (row == col) {
            win = true;
            for (int i = 0; i < n && win; ++i) {
                if (board[i][i] != p) win = false;
            }
            if (win) return p;
        }
        if (row + col == n - 1) {
            win = true;
            for (int i = 0; i < n && win; ++i) {
                if (board[i][n - 1 - i] != p) win = false;
            }
            if (win) return p;
        }
        return 0;
    }
public:
    TicTacToe(int n) : n(n) {
        board = vector<vector<int>>(n, vector<int>(n));
    }
    int move(int row, int col, int player) {
        board[row][col] = player;
        return status(row, col);
    }
};