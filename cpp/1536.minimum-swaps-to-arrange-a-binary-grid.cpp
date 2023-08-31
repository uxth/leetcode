/*
 * @lc app=leetcode id=1536 lang=cpp
 *
 * [1536] Minimum Swaps to Arrange a Binary Grid
 *
 * https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/
 *
 * algorithms
 * Medium (41.52%)
 * Likes:    187
 * Dislikes: 41
 * Total Accepted:    6.4K
 * Total Submissions: 15.3K
 * Testcase Example:  '[[0,0,1],[1,1,0],[1,0,0]]'
 *
 * Given an n x n binary grid, in one step you can choose two adjacent rows of
 * the grid and swap them.
 * 
 * A grid is said to be valid if all the cells above the main diagonal are
 * zeros.
 * 
 * Return the minimum number of steps needed to make the grid valid, or -1 if
 * the grid cannot be valid.
 * 
 * The main diagonal of a grid is the diagonal that starts at cell (1, 1) and
 * ends at cell (n, n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
 * Output: -1
 * Explanation: All rows are similar, swaps have no effect on the grid.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 200
 * grid[i][j] is 0 or 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> t(n); //t[i]: tailing zero count for i-th row        
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j = n;--j>=0 && !grid[i][j]; )  count++;                
            t[i] = count;
        }
        int ans = 0;
        for(int i=0;i< n;i++){
            int k = i;
            int req = n-1 - i; // desired tailing zero count
            while(k<n && t[k]<req) k++; // greedily find first swaping candidate and log the result into k. Note1
            if(k==n) return -1; // k is out of range. Fail in searching

            //Core part of the question: moving up k-th row up, moving down [i, k-1
            //Part 1: move k-th row up to i-th row
            ans += k-i; // accumulate the operation cost of moving k to i
            
            //Part 2: move the rest involved row downward by offset 1
            while(k>i){ // simulate swaping operation of two adjacent rows in range of [i, k-1 ]
                t[k] = t[k-1];
                k--;
            }
        }    
        
        return ans;
    }
};
// @lc code=end
// [[1,0,0,0],[1,1,1,1],[1,0,0,0],[1,0,0,0]]
// [[0,0,1],[1,1,0],[1,0,0]]
/* [[1,0,0,0,0,0],
    [0,1,0,1,0,0],
    [1,0,0,0,0,0],
    [1,1,1,0,0,0],
    [1,1,0,1,0,0],
    [1,0,0,0,0,0]]
*/
