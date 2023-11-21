/*

Description
Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of ‘B’ and ‘W’, which means black and white pixels respectively.

A black lonely pixel is character ‘B’ that located at a specific position where the same row and same column don’t have any other black pixels.

Example:

Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:

The range of width and height of the input 2D array is [1,500].
Solution
For each row, store the column indices in the row where the pixels are black. For each column, store the row indices in the column where the pixels are black.

Loop over each row. If a row contains exactly one pixel that is black, then obtain the column index of the black pixel. If the column contains exactly one pixel that is black, then the pixel is a lonely pixel. Count the number of lonely pixels and return.
*/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            if (rows[i] == 1) {
                for (int j = 0; j < n; ++j) {
                    if (picture[i][j] == 'B' && cols[j] == 1) {
                        ++res;
                        break;
                    }
                }
            }
        }
        return res;
    }
};