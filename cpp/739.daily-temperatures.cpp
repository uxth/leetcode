/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (63.30%)
 * Likes:    3269
 * Dislikes: 98
 * Total Accepted:    185.1K
 * Total Submissions: 289.9K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<int> temp;
        for(int i=T.size()-1; i>=0; --i)
        {
            while(!temp.empty() && T[temp.top()] <= T[i]) temp.pop();
            res[i] = temp.empty() ? 0 : temp.top() - i;
            temp.push(i);
            
        }
        return res;
    }
};
// @lc code=end
// [89,62,70,58,47,47,46,76,100,70]
