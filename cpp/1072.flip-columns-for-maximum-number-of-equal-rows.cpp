/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 *
 * https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/
 *
 * algorithms
 * Medium (60.82%)
 * Likes:    270
 * Dislikes: 24
 * Total Accepted:    10.8K
 * Total Submissions: 17.7K
 * Testcase Example:  '[[0,1],[1,1]]'
 *
 * Given a matrix consisting of 0s and 1s, we may choose any number of columns
 * in the matrix and flip every cell in that column.  Flipping a cell changes
 * the value of that cell from 0 to 1 or from 1 to 0.
 * 
 * Return the maximum number of rows that have all values equal after some
 * number of flips.
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
 * Input: [[0,1],[1,1]]
 * Output: 1
 * Explanation: After flipping no values, 1 row has all values equal.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1],[1,0]]
 * Output: 2
 * Explanation: After flipping values in the first column, both rows have equal
 * values.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,0,0],[0,0,1],[1,1,0]]
 * Output: 2
 * Explanation: After flipping values in the first two columns, the last two
 * rows have equal values.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= matrix.length <= 300
 * 1 <= matrix[i].length <= 300
 * All matrix[i].length's are equal
 * matrix[i][j] is 0 or 1
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> hmap;
        for(auto x: matrix){
            string s=""; 
            //s keeps track of relative ordering of elements in a row w.r.t the first element
            int top=x[0];
            for(int i : x)
                s += i==top ? '1' : '0';
            hmap[s]++; 
        }
        
        int result=0;
        for(auto &[key,val]:hmap)
            result=max(result,val); 
        //rows that have identical relative ordering, can be simultaneously toggled columnwise in order to make all
        //elements of any of those rows unique. So the answer is maximum number of rows with identical relative ordering.
        return result;
    }
};
// @lc code=end

