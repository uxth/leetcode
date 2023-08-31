/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 *
 * https://leetcode.com/problems/count-largest-group/description/
 *
 * algorithms
 * Easy (64.99%)
 * Likes:    103
 * Dislikes: 250
 * Total Accepted:    14.5K
 * Total Submissions: 22.4K
 * Testcase Example:  '13\r'
 *
 * Given an integer n. Each number from 1 to n is grouped according to the sum
 * of its digits. 
 * 
 * Return how many groups have the largest size.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 13
 * Output: 4
 * Explanation: There are 9 groups in total, they are grouped according sum of
 * its digits of numbers from 1 to 13:
 * [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups
 * with largest size.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: 2
 * Explanation: There are 2 groups [1], [2] of size 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 15
 * Output: 6
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 24
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> m;
        map<int,int> count;
        for(int i=1; i<=n; ++i)
        {
            int digits = 0;
            int n = i;
            while(n){digits+=n%10; n/=10;}
            ++count[++m[digits]];
        }
        return count.rbegin()->second;
    }
};
// @lc code=end

