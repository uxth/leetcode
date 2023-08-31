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

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> buckets(10, 0);
        for (int i = 0; i < str.size(); ++i) {
            buckets[str[i] - '0'] = i;
        }
        for (int i = 0; i < str.size(); ++i) {
            for (int k = 9; k > str[i] - '0'; --k) {
                if (buckets[k] <= i) continue;
                swap(str[i], str[buckets[k]]);
                return stoi(str);
            }
        }
        return num;
    }
};
// @lc code=end

