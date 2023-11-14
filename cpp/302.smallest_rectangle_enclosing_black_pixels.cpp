/*

Question
Formatted question description: https://leetcode.ca/all/302.html

You are given an m x n binary matrix image where 0 represents a white pixel and 1 represents a black pixel.

The black pixels are connected (i.e., there is only one black region). Pixels are connected horizontally and vertically.

Given two integers x and y that represents the location of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

You must write an algorithm with less than O(mn) runtime complexity

 

Example 1:



Input: image = [["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]], x = 0, y = 2
Output: 6
Example 2:

Input: image = [["1"]], x = 0, y = 0
Output: 1
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 100
image[i][j] is either '0' or '1'.
0 <= x < m
0 <= y < n
image[x][y] == '1'.
The black pixels in the image only form one component.
Algorithm
Key point:

there is only one black region. 只有一个黑区

So, no need to worry about 1s spread across the matrix.

Brute force: Traverse the entire array, if it encounters 1, update the rectangle.

Improvement, with a given black pixel (x, y) as the center, use the binary search to quickly find the upper, lower, left, and right critical points of the entire black area, and then directly calculate the area.

For binary search implementation
When implementing binary search, the choice between using while start < end or while start <= end depends on the specific problem and the range of values being searched.

Use while start < end when you want to continue the search until the range between start and end is narrowed down to a single value. This is the most common scenario in binary search.
Use while start <= end when you want to include the possibility of the target value being at either start or end. This is typically used when searching for a specific target value in a range that is inclusive.
After the termination of the binary search loop, both start and end will be at the same position, representing the point where the target value is expected to be. It’s generally safe to return either start or end in most cases, as they should be pointing to the same value.

However, it’s important to consider the problem requirements and the specific implementation details. Sometimes, the problem statement or the specific algorithm may require returning start or end specifically. Make sure to carefully read the problem description or consider any specific requirements when determining which variable to return.

*/


// OJ: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
// Time: O(MlogN + NlogM)
// Space: O(M + N)
class Solution {
public:
    int minArea(vector<vector<char>>& A, int x, int y) {
        int M = A.size(), N = A[0].size();
        auto getRowLength = [&]() {
            int L = 0, R = x; // search min x
            while (L <= R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N) R = mid - 1;
                else L = mid + 1;
            }
            int mn = L; // minX = L
            L = x, R = M - 1;
            while (L <= R) {
                int mid = (L + R) / 2, j = 0;
                while (j < N && A[mid][j] == '0') ++j;
                if (j < N) L = mid + 1;
                else R = mid - 1;
            }
            return L - mn; // maxX = R = L - 1
        };
        auto getColumnLength = [&]() {
            int L = 0, R = y; // search min y
            while (L <= R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M) R = mid - 1;
                else L = mid + 1;
            }
            int mn = L; // minY = L
            L = y, R = N - 1;
            while (L <= R) {
                int mid = (L + R) / 2, i = 0;
                while (i < M && A[i][mid] == '0') ++i;
                if (i < M) L = mid + 1;
                else R = mid - 1;
            }
            return L - mn; // maxX = R = L - 1
        };
        return getRowLength() * getColumnLength();
    }
};
