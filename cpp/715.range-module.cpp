/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 *
 * https://leetcode.com/problems/range-module/description/
 *
 * algorithms
 * Hard (38.53%)
 * Likes:    464
 * Dislikes: 35
 * Total Accepted:    19.4K
 * Total Submissions: 50K
 * Testcase Example:  '["RangeModule","addRange","removeRange","queryRange","queryRange","queryRange"]\n' +
  '[[],[10,20],[14,16],[10,14],[13,15],[16,17]]'
 *
 * A Range Module is a module that tracks ranges of numbers. Your task is to
 * design and implement the following interfaces in an efficient manner.
 * 
 * addRange(int left, int right) Adds the half-open interval [left, right),
 * tracking every real number in that interval.  Adding an interval that
 * partially overlaps with currently tracked numbers should add any numbers in
 * the interval [left, right) that are not already tracked.
 * 
 * queryRange(int left, int right) Returns true if and only if every real
 * number in the interval [left, right)
 * ⁠is currently being tracked.
 * 
 * removeRange(int left, int right) Stops tracking every real number currently
 * being tracked in the interval [left, right).
 * 
 * Example 1:
 * 
 * addRange(10, 20): null
 * removeRange(14, 16): null
 * queryRange(10, 14): true (Every number in [10, 14) is being tracked)
 * queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not
 * being tracked)
 * queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked,
 * despite the remove operation)
 * 
 * 
 * 
 * Note:
 * A half open interval [left, right) denotes all real numbers left .
 * 
 * 0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
 * The total number of calls to addRange in a single test case is at most 1000.
 * The total number of calls to queryRange in a single test case is at most
 * 5000.
 * The total number of calls to removeRange in a single test case is at most
 * 1000.
 * 
 */

// @lc code=start
class RangeModule {
public:
    set<pair<int,int>> s;
    RangeModule() {}
    
    void addRange(int x, int y) {
        auto it = s.upper_bound({x,INT_MAX});
        if (it != s.begin()){
            // if previous interval overlap merge and delete
            if ((--it)->second < x) ++it;
            else {
                x = it->first;
                y = max(it->second,y);
                it = s.erase(it);
            }
        }
        // while overlapping merge and delete
        while (it != s.end() && it->first <= y) {
            y = max(y,it->second);
            it = s.erase(it);
        }
        s.insert({x,y});
    }
    
    bool queryRange(int x, int y) {
        auto it = s.upper_bound({x,INT_MAX});
        return (it != s.begin() && (--it)->second >=y);
    }
    
    void removeRange(int x, int y) {
        auto it = s.upper_bound({x,INT_MAX});
        vector<pair<int,int>> to;
        if (it != s.begin()){
            if ((--it)->second <= x) ++it;
            else {
                // if previous interval overlap remove but add back the portion still covered
                to.push_back({it->first, x});
                if (it->second > y) to.push_back({y, it->second});
                it = s.erase(it);
            }
        }
        // while overlapping remove
        // if one of the removed intervals is partially covered by the remove range, add back the uncovered portion
        while (it != s.end() && it->first < y) {
            if (it->second > y) to.push_back({y, it->second});
            it = s.erase(it);
        }
        for (auto p : to) s.insert(p);
    }
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

