/*

Question
Formatted question description: https://leetcode.ca/all/308.html

Given a 2D matrix matrix, handle multiple queries of the following types:

Update the value of a cell in matrix.
Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
void update(int row, int col, int val) Updates the value of matrix[row][col] to be val.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 

Example 1:



Input
["NumMatrix", "sumRegion", "update", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [3, 2, 2], [2, 1, 4, 3]]
Output
[null, 8, null, 10]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e. sum of the left red rectangle)
numMatrix.update(3, 2, 2); // matrix changes from left image to right image
numMatrix.sumRegion(2, 1, 4, 3); // return 10 (i.e. sum of the right red rectangle)

 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-1000 <= matrix[i][j] <= 1000
0 <= row < m
0 <= col < n
-1000 <= val <= 1000
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 5000 calls will be made to sumRegion and update.
Algorithm
In the class NumMatrix, maintain the original matrix matrix and maintain another 2D array rowSums that has the same size as matrix and stores the sums of the elements to the left in the same row. Concretely, rowSums[i][j] is the sum of all elements from matrix[i][0] to matrix[i][j]. Also maintain rows and columns of matrix as well.

For the constructor, initialize the original matrix matrix, the 2D array rowSums, and rows and columns.

For update, calculate difference = val - matrix[row][column], update matrix[row][col] = val, and for col <= i < columns, update rowSums[row][i] += difference.

For sumRegion, if row1 > row2 or col1 > col2, then the region is invalid, so return 0. Otherwise, for each row from row1 to row2, calculate the sum of elements from column col1 to column col2. The sum in row row and columns range [col1, col2] is calculated as rowSums[row][col2] for col1 == 0, or rowSums[row][col2] - rowSums[row][col1 - 1] for col1 > 0.

*/

// Column Sum
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        mat = matrix;
        colSum.resize(matrix.size() + 1, vector<int>(matrix[0].size(), 0));
        for (int i = 1; i < colSum.size(); ++i) {
            for (int j = 0; j < colSum[0].size(); ++j) {
                colSum[i][j] = colSum[i - 1][j] + matrix[i - 1][j];
            }
        }
    }

    void update(int row, int col, int val) {
        for (int i = row + 1; i < colSum.size(); ++i) {
            colSum[i][col] += val - mat[row][col];
        }
        mat[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int j = col1; j <= col2; ++j) {
            res += colSum[row2 + 1][j] - colSum[row1][j];
        } 
        return res;
    }

private:
    vector<vector<int>> mat;
    vector<vector<int>> colSum;
};
