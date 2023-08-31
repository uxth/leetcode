/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (31.69%)
 * Likes:    692
 * Dislikes: 195
 * Total Accepted:    42.9K
 * Total Submissions: 135.5K
 * Testcase Example:  '12'
 *
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: 12
 * Output: 21
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 21
 * Output: -1
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> d;
        int m = n;
        while(n > 0)
        {
            d.push_back(n % 10);
            n /= 10;
        }

        reverse(d.begin(), d.end());
        next_permutation(d.begin(), d.end());
            
        long res = 0;
        for (int i = 0; i < d.size(); ++i)
            res = res * 10 + d[i];
        return res <= m || res > INT_MAX ? -1 : res;
    }
};
// @lc code=end

