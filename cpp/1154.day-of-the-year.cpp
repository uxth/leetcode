/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 *
 * https://leetcode.com/problems/day-of-the-year/description/
 *
 * algorithms
 * Easy (51.03%)
 * Likes:    411
 * Dislikes: 455
 * Total Accepted:    51.3K
 * Total Submissions: 105.3K
 * Testcase Example:  '"2019-01-09"'
 *
 * Given a string date representing a Gregorian calendar date formatted as
 * YYYY-MM-DD, return the day number of the year.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: date = "2019-01-09"
 * Output: 9
 * Explanation: Given date is the 9th day of the year in 2019.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: date = "2019-02-10"
 * Output: 41
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * date.length == 10
 * date[4] == date[7] == '-', and all other date[i]'s are digits
 * date represents a calendar date between Jan 1^st, 1900 and Dec 31^th, 2019.
 * 
 * 
 */

// @lc code=start
class Solution {
    const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool isLeap(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    }
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8));
        return (m > 2 && isLeap(y)) + accumulate(begin(days), begin(days) + m - 1, 0) + d;
    }
};
// @lc code=end

