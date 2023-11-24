/*

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [m, n], which means the matrix is m * n.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

 

Example 1:



Input: mat = [[0,0],[1,1]]
Output: 0
Example 2:



Input: mat = [[0,0],[0,1]]
Output: 1
Example 3:



Input: mat = [[0,0],[0,0]]
Output: -1
Example 4:



Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.

*/


// OJ: https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
// Time: O(M * logN)
// Space: O(1)
class Solution {
    int search(BinaryMatrix &A, int i, int end) {
        int L = 0, R = end - 1;
        while (L <= R) {
            int M = (L + R) / 2, val = A.get(i, M);
            if (val == 0) L = M + 1;
            else if (val == 1) {
                if (M - 1 < 0 || A.get(i, M - 1) == 0) return M;
                R = M - 1;
            }
        }
        return -1;
    }
public:
    int leftMostColumnWithOne(BinaryMatrix &A) {
        auto dim = A.dimensions();
        int M = dim[0], N = dim[1], ans = N;
        for (int i = 0; i < M; ++i) {
            int j = search(A, i, ans);
            if (j != -1) ans = j;
        }
        return ans == N ? -1 : ans;
    }
};