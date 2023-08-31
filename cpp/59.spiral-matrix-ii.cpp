/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (53.79%)
 * Likes:    1143
 * Dislikes: 120
 * Total Accepted:    204.3K
 * Total Submissions: 374.8K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int k = 1;
        int i = 0;
        while(k<=n*n)
        {
            int j = i;
            while( j < n - i ) res[i][j++] = k++;
            j = i + 1;
            while( j < n - i ) res[j++][n-i-1] = k++;
            j = n - i - 2;
            while( j > i ) res[n-i-1][j--] = k++;
            j = n - i - 1;
            while( j > i ) res[j--][i] = k++;
            i++;  
        }
        return res;
    }
};
// @lc code=end

