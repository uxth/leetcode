/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (39.32%)
 * Likes:    4556
 * Dislikes: 306
 * Total Accepted:    627.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 * 
 * Constraints:
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](vector<int>& i, vector<int>& j){if(i[0]==j[0]) return i[1]<j[1]; return i[0]<j[0];});
        vector<vector<int>> res{intervals[0]};
        for(int i=0; i<intervals.size(); ++i)
        {
            if(intervals[i][0] <= res.back()[1])
            {
                if(res[res.size()-1][1] < intervals[i][1])
                    res[res.size()-1][1] = intervals[i][1];
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

