/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (48.95%)
 * Likes:    949
 * Dislikes: 199
 * Total Accepted:    309.7K
 * Total Submissions: 617.4K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

// @lc code=start
class Solution {
public:
    int combination(int m, int n)
    {
        if(n == 0 || n == m) return 1;
        double res = 1;
        while(n)
        {
            res *= m--;
            res /= n--;
        }
        return (int)round(res);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        for(int i=0; i<=rowIndex; ++i)
        {
            res[i] = combination(rowIndex, i);
        }
        return res;
    }
};
// @lc code=end

