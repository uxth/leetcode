/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 *
 * https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
 *
 * algorithms
 * Medium (34.80%)
 * Likes:    423
 * Dislikes: 414
 * Total Accepted:    29.9K
 * Total Submissions: 85.4K
 * Testcase Example:  '"RXXLRXRXL"\n"XRLXXRRLX"'
 *
 * In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a
 * move consists of either replacing one occurrence of "XL" with "LX", or
 * replacing one occurrence of "RX" with "XR". Given the starting string start
 * and the ending string end, return True if and only if there exists a
 * sequence of moves to transform one string to the other.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
 * Output: true
 * Explanation: We can transform start to end following these steps:
 * RXXLRXRXL ->
 * XRXLRXRXL ->
 * XRLXRXRXL ->
 * XRLXXRRXL ->
 * XRLXXRRLX
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: start = "X", end = "L"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: start = "LLR", end = "RRL"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: start = "XL", end = "LX"
 * Output: true
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: start = "XLLR", end = "LXLX"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= start.length <= 10^4
 * start.length == end.length
 * Both start and end will only consist of characters in 'L', 'R', and 'X'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        if(start == end) return true;
        int n = start.size();
        string s1, s2;
        for (int i = 0; i < n; ++i) 
            if (start[i] != 'X') s1 += start[i];
        for (int i = 0; i < n; ++i) 
            if (end[i] != 'X') s2 += end[i];
        if (s1 != s2) return false;

        for (int i = 0, j = 0; i < n && j < n;) {
            if (start[i] == 'X') 
               i++;
            else if (end[j] == 'X') 
               j++;
            else {
                if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
                i++;
                j++;
            }
        }
        return true;
    }
};
// @lc code=end
// ""LLR"\n"RRL""
// ""XXRXXXXXXXRXRXXXLXXLXXLXXXXXRXXXXXXXXLXX"\n"XXXRXXXXRXXXXXXRXXXLXXXXXXXLXXLXXRXXLXXX""