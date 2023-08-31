/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 *
 * https://leetcode.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (53.31%)
 * Likes:    216
 * Dislikes: 95
 * Total Accepted:    15.2K
 * Total Submissions: 28.3K
 * Testcase Example:  '1'
 *
 * Starting with a positive integer N, we reorder the digits in any order
 * (including the original order) such that the leading digit is not zero.
 * 
 * Return true if and only if we can do this in a way such that the resulting
 * number is a power of 2.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 24
 * Output: false
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 46
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if((N&(N-1)) == 0) return true;
        string data = to_string(N);
        sort(data.begin(), data.end());
        do
        {
            if(data.front() == '0') continue;
            int d = stoi(data);
            if((d & (d-1)) == 0) return true;
        }while(next_permutation(data.begin(), data.end()));
        return false;
    }
};
// @lc code=end

