/*
 * @lc app=leetcode id=1124 lang=cpp
 *
 * [1124] Longest Well-Performing Interval
 *
 * https://leetcode.com/problems/longest-well-performing-interval/description/
 *
 * algorithms
 * Medium (32.74%)
 * Likes:    444
 * Dislikes: 62
 * Total Accepted:    11.9K
 * Total Submissions: 36.3K
 * Testcase Example:  '[9,9,6,0,6,6,9]'
 *
 * We are given hours, a list of the number of hours worked per day for a given
 * employee.
 * 
 * A day is considered to be a tiring day if and only if the number of hours
 * worked is (strictly) greater than 8.
 * 
 * A well-performing interval is an interval of days for which the number of
 * tiring days is strictly larger than the number of non-tiring days.
 * 
 * Return the length of the longest well-performing interval.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hours = [9,9,6,0,6,6,9]
 * Output: 3
 * Explanation: The longest well-performing interval is [9,9,6].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= hours.length <= 10000
 * 0 <= hours[i] <= 16
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int len = hours.size();
        vector<int> prefixSum(len+1, 0);
        for (int i = 1; i <= len; ++i) {
            prefixSum[i] = prefixSum[i-1] + (hours[i-1] > 8 ? 1 : -1);
        }
        stack<int> smdStack;
        for (int i = 0; i <= len; ++i) {
            if (smdStack.empty() || prefixSum[smdStack.top()] > prefixSum[i]) {
				// Trick, store index than value.
                smdStack.push(i);
            }
        }
        int res = 0;
        for (int j = len; j >= 0; --j) {
		    // For generalized problem:
		    // while (!smdStack.empty() && prefixSum[smdStack.top()]+K <= prefixSum[j]) {
            
			// For this problem:
			while (!smdStack.empty() && prefixSum[smdStack.top()] < prefixSum[j]) {
                res = max(res, j - smdStack.top());
                smdStack.pop();
            }
        }
        return res;
    }
};
// @lc code=end
// [9,9,6,0,6,6,9]
// [9,6,6,0,6,9,9]
// [9,9,6,0,6,6,9]