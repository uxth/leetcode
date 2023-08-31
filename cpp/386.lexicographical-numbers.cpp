/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (53.43%)
 * Likes:    692
 * Dislikes: 85
 * Total Accepted:    61.9K
 * Total Submissions: 114.9K
 * Testcase Example:  '13'
 *
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        dfs(0, n, res);
        
        return res;
    }
    
    void dfs(int x, int n, vector<int>& res) {
        
        for (int i = 0; i <= 9; ++i) {
            int num = x * 10 + i;
            
            if (num > 0 && num <= n) {
                res.push_back(num);
                dfs(num, n, res);
            }
        }
    }
};
// @lc code=end

