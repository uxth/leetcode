/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (51.53%)
 * Likes:    524
 * Dislikes: 155
 * Total Accepted:    53.1K
 * Total Submissions: 102.6K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list. 
 * 
 * Example 1:
 * 
 * Input: ["23:59","00:00"]
 * Output: 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        sort(timePoints.begin(), timePoints.end());
        for(int i=0;i<timePoints.size(); ++i)
        {
            int j = i == 0 ? timePoints.size() - 1 : i - 1;
            string si = timePoints[i];
            int ti = (si[0] * 10 + si[1]) * 60 + si[3] * 10 + si[4];
            string sj = timePoints[j];
            int tj = (sj[0] * 10 + sj[1]) * 60 + sj[3] * 10 + sj[4];
            int t = (ti - tj + 1440) % 1440;
            res = min(res, t);
        }
        return res;       
    }
};
// @lc code=end
// ["05:31","22:08","00:35"]
