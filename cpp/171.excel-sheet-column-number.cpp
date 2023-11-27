/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (60.56%)
 * Likes:    4612
 * Dislikes: 355
 * Total Accepted:    646.1K
 * Total Submissions: 1M
 * Testcase Example:  '"A"'
 *
 * Given a string columnTitle that represents the column title as appears in an
 * Excel sheet, return its corresponding column number.
 * 
 * For example:
 * 
 * 
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 * ...
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: columnTitle = "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: columnTitle = "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: columnTitle = "ZY"
 * Output: 701
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= columnTitle.length <= 7
 * columnTitle consists only of uppercase English letters.
 * columnTitle is in the range ["A", "FXSHRXW"].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(int i=0; i<columnTitle.size(); ++i){
            res = res * 26 + (columnTitle[i] - 'A' + 1);
        }
        return res;
    }
};
// @lc code=end

