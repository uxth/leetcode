/*
 * @lc app=leetcode id=1678 lang=golang
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
func interpret(command string) string {
    return strings.ReplaceAll(strings.ReplaceAll(command, "()", "o"), "(al)", "al")

}
// @lc code=end

