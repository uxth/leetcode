/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 *
 * https://leetcode.com/problems/zuma-game/description/
 *
 * algorithms
 * Hard (39.82%)
 * Likes:    220
 * Dislikes: 223
 * Total Accepted:    14.3K
 * Total Submissions: 36K
 * Testcase Example:  '"WRRBBW"\n"RB"'
 *
 * Think about Zuma Game. You have a row of balls on the table, colored red(R),
 * yellow(Y), blue(B), green(G), and white(W). You also have several balls in
 * your hand.
 * 
 * Each time, you may choose a ball in your hand, and insert it into the row
 * (including the leftmost place and rightmost place). Then, if there is a
 * group of 3 or more balls in the same color touching, remove these balls.
 * Keep doing this until no more balls can be removed.
 * 
 * Find the minimal balls you have to insert to remove all the balls on the
 * table. If you cannot remove all the balls, output -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = "WRRBBW", hand = "RB"
 * Output: -1
 * Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = "WWRRBBWW", hand = "WRBRW"
 * Output: 2
 * Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW ->
 * empty
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = "G", hand = "GGGGG"
 * Output: 2
 * Explanation: G -> G[G] -> GG[G] -> empty 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: board = "RBYYBBRRB", hand = "YRBGB"
 * Output: 3
 * Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] ->
 * BB[B] -> empty 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * You may assume that the initial row of balls on the table won’t have any 3
 * or more consecutive balls with the same color.
 * 1 <= board.length <= 16
 * 1 <= hand.length <= 5
 * Both input strings will be non-empty and only contain characters
 * 'R','Y','B','G','W'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    
    string shrink(string s) {
        while (s.size() > 0) {
            int start = 0;
            bool done = true;
            for (int i = 0; i <= s.size(); i++) {
                if (i == s.size() || s[i] != s[start]) {
                    if (i - start >= 3) {
                        s = s.substr(0, start) + s.substr(i);
                        done = false;
                        break;
                    }
                    start = i;
                }
            }
            if (done) break;
        }
        return s;
    }

    int helper(string b, string h) {
        if (b.empty()) return 0;
        if (h.empty()) return 6;
        int res = 6;
        for (int i = 0; i < h.size(); i++) {
            int j = 0;
            int n = b.size();
            while (j < n) {
                int k = b.find(h[i], j);
                if (k == string::npos) break;
                if (k < n - 1 && b[k] == b[k + 1]) { // 2 consecutive balls with same color on board
                    string nextb = shrink(b.substr(0, k) + b.substr(k + 2)); // shrink the string until no 3 or more consecutive balls in same color
                    if (nextb.empty()) return 1; // this is the best result for current board, no need to continue
                    string nexth = h;
                    nexth.erase(i, 1); // remove the used ball from hand
                    res = min(res, helper(nextb, nexth) + 1);
                    k++;
                }
                else if (i > 0 && h[i] == h[i - 1]) { // 2 balls with same color in hand
                    string nextb = shrink(b.substr(0, k) + b.substr(k + 1)); // shrink the string until no 3 or more consecutive balls in same color
                    if (nextb.empty()) return 2;  // this is the best result for current board, no need to continue
                    string nexth = h;
                    nexth.erase(i, 1); // remove the used balls from hand
                    nexth.erase(i - 1, 1);
                    res = min(res, helper(nextb, nexth) + 2);
                }
                j = k + 1;
            }
        }
        return res;
    }
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int res = helper(board, hand);
        return res > hand.size() ? -1 : res;
    }
};
// @lc code=end

