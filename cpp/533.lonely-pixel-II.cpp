/*

Description
Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R.
The picture is represented by a 2D char array consisting of ‘B’ and ‘W’, which means black and white pixels respectively.

Example:

Input:                                            
[['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'W', 'B', 'W', 'B', 'W']] 

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index                                            
0    [['W', 'B', 'W', 'B', 'B', 'W'],    
1     ['W', 'B', 'W', 'B', 'B', 'W'],    
2     ['W', 'B', 'W', 'B', 'B', 'W'],    
3     ['W', 'W', 'B', 'W', 'B', 'W']]    
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.
Note:

The range of width and height of the input 2D array is [1,200].
Solution
Since this problem requires the rows should have exactly the same columns that have black pixels, map each row as a string to the count of the row, which means the number of rows that have this content.

Only consider the rows that have counts exactly N. For each such row, the row should contain exactly N black pixels, and for each position that is a black pixel, count the number of black pixels in the column. If there are exactly N black pixels in the column, then add N to the result. Finally, return the result.

*/

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size(), n = picture[0].size();
        vector<int> rows(m);
        unordered_map<int, vector<int>> cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    cols[j].push_back(i);
                }
            }
        }
        vector<vector<bool>> t(m, vector<bool>(m, false));
        for (int i = 0; i < m; ++i) {
            for (int k = i; k < m; ++k) {
                t[i][k] = i == k || all(picture[i], picture[k]);
                t[k][i] = t[i][k];
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            if (rows[i] == target) {
                for (int j = 0; j < n; ++j) {
                    if (cols[j].size() == target) {
                        bool check = true;
                        for (int k : cols[j]) check = check && t[i][k];
                        if (check) ++res;
                    }
                }
            }
        }
        return res;
    }

    bool all(vector<char>& row1, vector<char>& row2) {
        int n = row1.size();
        for (int j = 0; j < n; ++j)
            if (row1[j] != row2[j]) return false;
        return true;
    }
};