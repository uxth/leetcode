/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 *
 * https://leetcode.com/problems/largest-plus-sign/description/
 *
 * algorithms
 * Medium (45.96%)
 * Likes:    487
 * Dislikes: 99
 * Total Accepted:    21.9K
 * Total Submissions: 47.6K
 * Testcase Example:  '5\n[[4,2]]'
 *
 * 
 * In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except
 * those cells in the given list mines which are 0.  What is the largest
 * axis-aligned plus sign of 1s contained in the grid?  Return the order of the
 * plus sign.  If there is none, return 0.
 * 
 * An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1
 * along with 4 arms of length k-1 going up, down, left, and right, and made of
 * 1s.  This is demonstrated in the diagrams below.  Note that there could be
 * 0s or 1s beyond the arms of the plus sign, only the relevant area of the
 * plus sign is checked for 1s.
 * 
 * 
 * Examples of Axis-Aligned Plus Signs of Order k:
 * Order 1:
 * 000
 * 010
 * 000
 * 
 * Order 2:
 * 00000
 * 00100
 * 01110
 * 00100
 * 00000
 * 
 * Order 3:
 * 0000000
 * 0001000
 * 0001000
 * 0111110
 * 0001000
 * 0001000
 * 0000000
 * 
 * 
 * Example 1:
 * Input: N = 5, mines = [[4, 2]]
 * Output: 2
 * Explanation:
 * 11111
 * 11111
 * 11111
 * 11111
 * 11011
 * In the above grid, the largest plus sign can only be order 2.  One of them
 * is marked in bold.
 * 
 * 
 * Example 2:
 * Input: N = 2, mines = []
 * Output: 1
 * Explanation:
 * There is no plus sign of order 2, but there is of order 1.
 * 
 * 
 * Example 3:
 * Input: N = 1, mines = [[0, 0]]
 * Output: 0
 * Explanation:
 * There is no plus sign, so return 0.
 * 
 * 
 * Note:
 * N will be an integer in the range [1, 500].
 * mines will have length at most 5000.
 * mines[i] will be length 2 and consist of integers in the range [0, N-1].
 * (Additionally, programs submitted in C, C++, or C# will be judged with a
 * slightly smaller time limit.)
 * 
 */

// @lc code=start
class Solution {
public:

    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> m(N, vector<int>(N, 1));
        vector<vector<int>> h(N, vector<int>(N, 0));
        vector<vector<int>> v(N, vector<int>(N, 0));
        for(vector<int>& mine : mines) m[mine[0]][mine[1]] = 0;

        for(int i=0; i<N; ++i)
        {
            h[i][0] = m[i][0];
            for(int j=1; j<N-1; ++j)
                if(m[i][j]) 
                    h[i][j] = 1 + h[i][j-1];

            h[i][N-1] = m[i][N-1];
            for(int j=N-2; j>=0; --j)
                if(m[i][j])
                    h[i][j] = min(h[i][j], 1 + h[i][j+1]);
        }
        for(int j=0; j<N; ++j)
        {
            v[0][j] = m[0][j];
            for(int i=1; i<N-1; ++i)
                if(m[i][j])
                    v[i][j] = 1 + v[i-1][j];
            v[N-1][j] = m[N-1][j];
            for(int i=N-2; i>=0; --i)
                if(m[i][j])
                    v[i][j] = min(v[i][j], 1 + v[i+1][j]);
        }
        int res = 0;
        for(int i=0; i<N; ++i)
            for(int j=0;j<N; ++j)
                res = max(res, min(h[i][j], v[i][j]));
        return res;
    }
};
// @lc code=end

