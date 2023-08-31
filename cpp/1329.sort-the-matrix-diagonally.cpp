/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 *
 * https://leetcode.com/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (78.37%)
 * Likes:    337
 * Dislikes: 94
 * Total Accepted:    17.1K
 * Total Submissions: 21.8K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * Given a m * n matrix mat of integers, sort it diagonally in ascending order
 * from the top-left to the bottom-right then return the sorted array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return mat;
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> data;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                data[i-j].push_back(mat[i][j]);
            }
        }
        for(auto& i : data)
        {
            sort(i.second.begin(), i.second.end(), greater<int>());
        }

        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                mat[i][j] = data[i-j].back();
                data[i-j].pop_back();
            }
        }
        return mat;
    }
};
// @lc code=end
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
