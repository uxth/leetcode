/*

Description
Given a non-empty 2D array grid of 0’s and 1’s, an island is a group of 1’s (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

Example 1:

11000
10000
00001
00011
Given the above grid map, return 1.

Notice that:

11
1
and

 1
11
are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.

Example 2:

11100
10001
01001
01110
Given the above grid map, return 2.

Here are the two distinct islands:

111
1
and

1
1
Notice that:

111
1
and

1
111
are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.

Note: The length of each dimension in the given grid does not exceed 50.

Solution
This is a follow-up problem of problem 694. In this problem, rotation and reflection are also considered.

The basic idea is still using breadth first search. However, the way to determine an island’s shape is different.

After rotation, there are at most 4 different states of the shape. After rotation and reflection, there are at most 8 different states of the shape. For each shape met, consider all 8 states, and for each state, use a list to store the positions, where each element in the list is an integer that can uniquely determine a position. Sort the list and convert it into a string. Use the greatest string to represent the state. Use a set to store the strings so that each state corresponds to one element in the set, whether it has been rotated or reflected. Finally, return the set’s size.

*/

typedef pair<int, int> PII;

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        set<vector<PII>> s;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    vector<PII> shape;
                    dfs(i, j, grid, shape);
                    s.insert(normalize(shape));
                }
            }
        }
        return s.size();
    }

    vector<PII> normalize(vector<PII>& shape) {
        vector<vector<PII>> shapes(8);
        for (auto& e : shape) {
            int i = e.first, j = e.second;
            shapes[0].push_back({i, j});
            shapes[1].push_back({i, -j});
            shapes[2].push_back({-i, j});
            shapes[3].push_back({-i, -j});
            shapes[4].push_back({j, i});
            shapes[5].push_back({j, -i});
            shapes[6].push_back({-j, -i});
            shapes[7].push_back({-j, i});
        }
        for (auto& e : shapes) {
            sort(e.begin(), e.end());
            for (int k = e.size() - 1; k >= 0; --k) {
                e[k].first -= e[0].first;
                e[k].second -= e[0].second;
            }
        }
        sort(shapes.begin(), shapes.end());
        return shapes[0];
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<PII>& shape) {
        shape.push_back({i, j});
        grid[i][j] = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1)
                dfs(x, y, grid, shape);
        }
    }
};