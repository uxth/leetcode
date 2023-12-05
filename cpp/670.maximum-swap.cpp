/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 *
 * https://leetcode.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (43.59%)
 * Likes:    1127
 * Dislikes: 75
 * Total Accepted:    75.7K
 * Total Submissions: 172.1K
 * Testcase Example:  '2736'
 *
 * 
 * Given a non-negative integer, you could swap two digits at most once to get
 * the maximum valued number. Return the maximum valued number you could get.
 * 
 * 
 * Example 1:
 * 
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The given number is in the range [0, 10^8]
 * 
 * 
 */

// OJ: https://leetcode.com/problems/maximum-swap/
// Time: O(N)
// Space: O(1)
// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num), memo(digits.size(), '\0');
        int maxIndex = digits.size() - 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] > digits[maxIndex]) maxIndex = i;
            memo[i] = maxIndex;
        }
        for (int i = 0; i < digits.size(); ++i) {
            if (memo[i] > i && digits[i] != digits[memo[i]]) {
                swap(digits[i], digits[memo[i]]);
                return stoi(digits);
            }
        }
        return num;
    }
};
// @lc code=end

