/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.find("01") == -1)
            return true;
        return false;
    }
};
// @lc code=end

