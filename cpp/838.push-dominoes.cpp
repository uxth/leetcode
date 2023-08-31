/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 *
 * https://leetcode.com/problems/push-dominoes/description/
 *
 * algorithms
 * Medium (48.44%)
 * Likes:    652
 * Dislikes: 70
 * Total Accepted:    23.5K
 * Total Submissions: 48.1K
 * Testcase Example:  '".L.R...LR..L.."'
 *
 * There are N dominoes in a line, and we place each domino vertically
 * upright.
 * 
 * In the beginning, we simultaneously push some of the dominoes either to the
 * left or to the right.
 * 
 * 
 * 
 * After each second, each domino that is falling to the left pushes the
 * adjacent domino on the left.
 * 
 * Similarly, the dominoes falling to the right push their adjacent dominoes
 * standing on the right.
 * 
 * When a vertical domino has dominoes falling on it from both sides, it stays
 * still due to the balance of the forces.
 * 
 * For the purposes of this question, we will consider that a falling domino
 * expends no additional force to a falling or already fallen domino.
 * 
 * Given a string "S" representing the initial state. S[i] = 'L', if the i-th
 * domino has been pushed to the left; S[i] = 'R', if the i-th domino has been
 * pushed to the right; S[i] = '.', if the i-th domino has not been pushed.
 * 
 * Return a string representing the final state. 
 * 
 * Example 1:
 * 
 * 
 * Input: ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "RR.L"
 * Output: "RR.L"
 * Explanation: The first domino expends no additional force on the second
 * domino.
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= N <= 10^5
 * String dominoes contains only 'L', 'R' and '.'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<float> dp(dominoes.size(), 0);
        for(int i=0, dis=0; i<dominoes.size(); ++i)
        {
            if(dominoes[i] == 'R') {dis=1; dp[i] = 1.0/dis;}
            else if(dominoes[i] == '.' && dis) {dis++; dp[i] += 1.0/dis;}
            else {dis = 0;}
        }
        for(int i=dominoes.size()-1, dis=0; i>=0; --i)
        {
            if(dominoes[i] == 'L') {dis=-1; dp[i] = 1.0/dis;}
            else if(dominoes[i] == '.' && dis) {dis--; dp[i] += 1.0/dis;}
            else {dis = 0;}
        }
        string res;
        for(int i = 0; i<dp.size(); ++i)
        {
            if(abs(dp[i]) < 1e-5) res+=dominoes[i];
            else if(dp[i] > 1e-5) res+="R";
            else res+="L";
        }
        return res;
    }
};
// @lc code=end

