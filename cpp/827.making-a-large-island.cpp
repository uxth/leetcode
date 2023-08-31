/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 *
 * https://leetcode.com/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (45.62%)
 * Likes:    457
 * Dislikes: 14
 * Total Accepted:    18.7K
 * Total Submissions: 40.9K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
 * 
 * After, what is the size of the largest island? (An island is a
 * 4-directionally connected group of 1s).
 * 
 * Example 1:
 * 
 * 
 * Input: [[1, 0], [0, 1]]
 * Output: 3
 * Explanation: Change one 0 to 1 and connect two 1s, then we get an island
 * with area = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1, 1], [1, 0]]
 * Output: 4
 * Explanation: Change the 0 to 1 and make the island bigger, only one island
 * with area = 4.
 * 
 * Example 3:
 * 
 * 
 * Input: [[1, 1], [1, 1]]
 * Output: 4
 * Explanation: Can't change any 0 to 1, only one island with area = 4.
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * 1 <= grid.length = grid[0].length <= 50.
 * 0 <= grid[i][j] <= 1.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int get(int i, int j, vector<vector<int>>& g) {
        return (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) ? 0 : g[i][j];
    }
    int paint(int i, int j, int clr, vector<vector<int>>& g)
    {
        if (get(i, j, g) != 1) return 0;
        g[i][j] = clr;
        return 1 + paint(i + 1, j, clr, g) + paint(i - 1, j, clr, g) + paint(i, j + 1, clr, g) + paint(i, j - 1, clr, g);
    }
    int largestIsland(vector<vector<int>>& g) {
        vector<int> sizes = { 0, 0 }; // sentinel values; colors start from 2.
        int res = 0;
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
                if (g[i][j] == 1) sizes.push_back(paint(i, j, sizes.size(), g));
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
                if (g[i][j] == 0) {
                    unordered_set<int> s = { get(i + 1, j, g), get(i - 1, j, g), get(i, j + 1, g), get(i, j - 1, g) };
                    res = max(res, 1 + accumulate(begin(s), end(s), 0, [&](int total, int item) {return total + sizes[item]; }));
                }
        return res == 0 ? g.size() * g[0].size() : res;
    }
};
// @lc code=end
// [[0,0],[0,0]][[0,0],[0,0]]


