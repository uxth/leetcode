/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 *
 * https://leetcode.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (67.26%)
 * Likes:    1722
 * Dislikes: 55
 * Total Accepted:    141.4K
 * Total Submissions: 208.9K
 * Testcase Example:  '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * Given two lists of closed intervals, each list of intervals is pairwise
 * disjoint and in sorted order.
 * 
 * Return the intersection of these two interval lists.
 * 
 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real
 * numbers x with a <= x <= b.  The intersection of two closed intervals is a
 * set of real numbers that is either empty, or can be represented as a closed
 * interval.  For example, the intersection of [1, 3] and [2, 4] is [2,
 * 3].)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: A = [[0,2],[5,10],[13,23],[24,25]], B =
 * [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<int,int> m;
        vector<vector<int>> res;
        for(auto& i : A) m[i[0]] = i[1];
        for(auto& i : B)
        {
            auto it = m.lower_bound(i[0]);
            if(it != m.begin()) --it;
            while(it != m.end() && it->first <= i[1])
            {
                if(it->second >= i[0])
                {
                    res.push_back({max(it->first, i[0]), min(it->second, i[1])});
                }
                ++it;
            }
        }
        return res;
    }
};
// @lc code=end

