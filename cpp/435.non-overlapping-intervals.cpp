/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (42.91%)
 * Likes:    1492
 * Dislikes: 44
 * Total Accepted:    106.3K
 * Total Submissions: 244.5K
 * Testcase Example:  '[[1,2]]'
 *
 * Given a collection of intervals, find the minimum number of intervals you
 * need to remove to make the rest of the intervals non-overlapping.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of intervals are
 * non-overlapping.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of intervals
 * non-overlapping.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may assume the interval's end point is always bigger than its start
 * point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't
 * overlap each other.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a[0]<b[0];});
        int j=0;
        int res=0;
        for(int i=1; i<intervals.size(); ++i)
        {
            if(intervals[i][0]<intervals[j][1]) 
            {
                res++;
                if(intervals[i][1] < intervals[j][1]) j=i;
            }
            else 
                j=i;
        }

        return res;
    }
};
// @lc code=end
// [[1,2],[1,3],[1,4]]
// [[1,100],[11,22],[1,11],[2,12]]