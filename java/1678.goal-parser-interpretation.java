/*
 * @lc app=leetcode id=1678 lang=java
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
class Solution {
    public String interpret(String command) {
        return command.replace("(al)", "al").replace("()", "o");
    }
}
// @lc code=end

