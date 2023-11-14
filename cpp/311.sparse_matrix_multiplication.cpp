/*

Question
Formatted question description: https://leetcode.ca/all/311.html

Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

 

Example 1:



Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
Output: [[7,0,0],[-7,0,3]]
Example 2:

Input: mat1 = [[0]], mat2 = [[0]]
Output: [[0]]
 

Constraints:

m == mat1.length
k == mat1[i].length == mat2.length
n == mat2[i].length
1 <= m, n, k <= 100
-100 <= mat1[i][j], mat2[i][j] <= 100
Algorithm
Make sure that A[i][k] is not 0 before continuing to calculate, and then traverse the kth row of matrix B. If B[K][J] is not 0, accumulate the result matrix res[i][j] += A[i][k] * B[k][j], so that we can efficiently calculate the multiplication of the sparse matrix.

*/

// OJ: https://leetcode.com/problems/sparse-matrix-multiplication/
// Time: O(MNK)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int M = A.size(), K = A[0].size(), N = B[0].size();
        vector<vector<int>> ans(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < K; ++k) {
                    ans[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return ans;
    }
};
