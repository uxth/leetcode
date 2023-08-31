/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 *
 * https://leetcode.com/problems/shifting-letters/description/
 *
 * algorithms
 * Medium (44.61%)
 * Likes:    308
 * Dislikes: 61
 * Total Accepted:    25.6K
 * Total Submissions: 57.3K
 * Testcase Example:  '"abc"\n[3,5,9]'
 *
 * We have a string S of lowercase letters, and an integer array shifts.
 * 
 * Call the shift of a letter, the next letter in the alphabet, (wrapping
 * around so that 'z' becomes 'a'). 
 * 
 * For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
 * 
 * Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x
 * times.
 * 
 * Return the final string after all such shifts to S are applied.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "abc", shifts = [3,5,9]
 * Output: "rpl"
 * Explanation: 
 * We start with "abc".
 * After shifting the first 1 letters of S by 3, we have "dbc".
 * After shifting the first 2 letters of S by 5, we have "igc".
 * After shifting the first 3 letters of S by 9, we have "rpl", the answer.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length = shifts.length <= 20000
 * 0 <= shifts[i] <= 10 ^ 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int count = 0;
        for(int i=S.size()-1; i>=0; --i)
        {
            S[i] = (S[i]-'a' + shifts[i] + count) % 26 + 'a';
            count += shifts[i];
            count %= 26;
        }
        return S;
    }
};
// @lc code=end
// "mkgfzkkuxownxvfvxasy"\n[505870226,437526072,266740649,224336793,532917782,311122363,567754492,595798950,81520022,684110326,137742843,275267355,856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513]
