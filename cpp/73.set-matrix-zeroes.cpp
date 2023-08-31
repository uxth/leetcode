/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (43.96%)
 * Likes:    2958
 * Dislikes: 349
 * Total Accepted:    386.4K
 * Total Submissions: 876.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given an m x n matrix. If an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // void setZeroes(vector<vector<int>>& matrix) {
    //     vector<int> col(matrix[0].size(), 1);
    //     for(int i=0; i<matrix.size(); ++i)
    //     {
    //         bool zero = false;
    //         for(int j=0; j<matrix[0].size(); ++j)
    //         {
    //             if(matrix[i][j] == 0)
    //             {
    //                 col[j] = 0;
    //                 zero = true;
    //                 int k = i;
    //                 while(--k>=0)matrix[k][j]=0;
    //             }
    //             if(col[j] == 0) matrix[i][j] = 0;
    //         }
    //         if(zero)
    //         {
    //             for(int j=0;j<matrix[0].size(); ++j) matrix[i][j] = 0;
    //         }
    //     }
    // }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        vector<int> col(n, 1), row(m, 1);
        for(int i=0;i<m;++i) for(int j=0;j<n;++j)
            if(matrix[i][j] == 0) col[j] = row[i]= 0;
        for(int i=0;i<m;++i) for(int j=0;j<n;++j)
            if(row[i] == 0 || col[j] == 0) matrix[i][j] = 0;
    }

    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size(); int n = matrix[0].size();
    //     bool row = false;
    //     for(int j=0;j<n;++j)if(matrix[0][j]==0) {row=true;break;}
    //     for(int i=1;i<m;++i)
    //     {
    //         bool flag = false;
    //         for(int j=0;j<n;++j)
    //         {
    //             if(matrix[i][j]==0)
    //             {
    //                 matrix[0][j]=0;
    //                 flag=true;
    //                 int k=i-1;
    //                 while(k>=0) matrix[k--][j]=0;
    //             }
    //             if(matrix[0][j]==0)matrix[i][j] = 0;
    //         }
    //         if(flag) for(int j=0;j<n;++j)matrix[i][j]=0;
    //     }
    //     if(row)for(int j=0;j<n;++j)matrix[0][j]=0;
    // }
};
// @lc code=end
// [[1,2,3,4],[5,0,5,2],[8,9,2,0],[5,7,2,1]]
// [[2147483647,2,9],[2,6,7],[1,8,8],[5,0,1],[9,6,0]]
