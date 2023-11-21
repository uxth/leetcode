/*

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.

Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:

11
1
and

 1
11
are considered different island shapes, because we do not consider reflection / rotation.

Note: The length of each dimension in the given grid does not exceed 50.

Companies:
Amazon, Google, Facebook, Microsoft, Lyft

Related Topics:
Hash Table, Depth-first Search

Similar Questions:

Number of Islands (Medium)
Number of Distinct Islands II (Hard)

*/


// OJ: https://leetcode.com/problems/number-of-distinct-islands/
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/number-of-distinct-islands/discuss/194673/C%2B%2B-easy-to-understand
class Solution {
private:
    unordered_set<string> s;
    int M, N;
    void explore(vector<vector<int>>& grid, int x, int y, string &path, char dir) {
        if (x < 0 || x >= M || y < 0 || y >= N || !grid[x][y]) return;
        grid[x][y] = 0;
        path.push_back(dir);
        explore(grid, x + 1, y, path, 'd');
        explore(grid, x, y + 1, path, 'r');
        explore(grid, x - 1, y, path, 'u');
        explore(grid, x, y - 1, path, 'l');
        path.push_back('x');
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                string path;
                explore(grid, i, j, path, 'o');
                if (path.size()) s.insert(path);
            }
        }
        return s.size();
    }
};