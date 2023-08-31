/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 *
 * https://leetcode.com/problems/remove-covered-intervals/description/
 *
 * algorithms
 * Medium (58.04%)
 * Likes:    182
 * Dislikes: 13
 * Total Accepted:    11.2K
 * Total Submissions: 19.3K
 * Testcase Example:  '[[1,4],[3,6],[2,8]]'
 *
 * Given a list of intervals, remove all intervals that are covered by another
 * interval in the list. Interval [a,b) is covered by interval [c,d) if and
 * only if c <= a and b <= d.
 * 
 * After doing so, return the number of remaining intervals.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,4],[3,6],[2,8]]
 * Output: 2
 * Explanation: Interval [3,6] is covered by [2,8], therefore it is
 * removed.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 1000
 * 0 <= intervals[i][0] < intervals[i][1] <= 10^5
 * intervals[i] != intervals[j] for all i != j
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int removeCoveredIntervals(vector<vector<int>>& intervals) {
    //     int res = 0, left = -1, right = -1;
    //     sort(intervals.begin(), intervals.end());
    //     for (auto& v: intervals) {
    //         if (v[0] > left && v[1] > right) {
    //             left = v[0];
    //             ++res;
    //         }
    //         right = max(right, v[1]);
    //     }
    //     return res;
    // }
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){if(a[0]==b[0]) return a[1] > b[1]; return a[0] < b[0];});
        int res = 0;
        int right = 0;
        for(auto& i : intervals)
        {
            if(i[1] > right)
            {
                res++;
                right = i[1];
            }
        }
        return res;
    }
};
// @lc code=end

