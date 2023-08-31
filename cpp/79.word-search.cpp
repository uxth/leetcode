/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (35.60%)
 * Likes:    4344
 * Dislikes: 202
 * Total Accepted:    529.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(vector<vector<char>>& board, int y, int x, string& word, int i, vector<vector<bool>>& visited)
    {
        int m = board.size();
        int n = board[0].size();
        if(y<0||x<0||y>=m||x>=n) return false;
        if(board[y][x] != word[i] || visited[y][x]) return false;
        if(i==word.size()-1) return true;
        visited[y][x] = true;
        for(auto& d : dir)
            if(dfs(board, y+d.first, x+d.second, word, i+1, visited)) return true;
        visited[y][x] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; ++i) for(int j=0; j<n; ++j)
            if(dfs(board, i, j, word, 0, visited)) return true;
        return false;
    }
};
// @lc code=end

