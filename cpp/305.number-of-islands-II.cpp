/*

Question
Formatted question description: https://leetcode.ca/all/305.html

305. Number of Islands II
Level
Hard

Description
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]

Output: [1,1,2,3]

Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:

Can you do it in time complexity O(k log mn), where k is the length of the positions?

Algorithm
Union Find.

1 . Native UF

p = list(range(n))

def find(x):
    if p[x] != x:
        p[x] = find(p[x])
    return p[x]

# union
p[find(a)] = find(b)
2 . UF with size

p = list(range(n))
size = [1] * n

def find(x):
    if p[x] != x:
        p[x] = find(p[x])
    return p[x]

if find(a) != find(b):
    size[find(b)] += size[find(a)]
    p[find(a)] = find(b)
3 . UF with distance to root

p = list(range(n))
d = [0] * n

def find(x):
    if p[x] != x:
        t = find(p[x])
        d[x] += d[p[x]]
        p[x] = t
    return p[x]

p[find(a)] = find(b)
d[find(a)] = distance
Algorithm - 2 - BFS
Each time a position is visited, first check whether the position is already a land cell.

If so, add the current number of islands to the result list, and continue with the next position.
Otherwise, check whether the position is adjacent to at least one land cell.
If there is no adjacent land cell, then a new island is added, so add a greater island number to the result list, and update the new land cell with a new island number.
Otherwise, find the minimum island number that is adjacent to the new land cell, do breadth first search on all cells adjacent to the new land cell, and update all reachable cells with the smallest island number. The number of islands may remain unchanged or decrease, and add the updated number of islands to the result list.
Finally, return the result list.
*/

class Solution {
public:
    vector<int> p;

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        p.resize(m * n);
        for (int i = 0; i < p.size(); ++i) p[i] = i;
        vector<vector<int>> grid(m, vector<int>(n));
        vector<int> ans;
        int cnt = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (auto& pos : positions) {
            int i = pos[0], j = pos[1];
            if (grid[i][j] == 1) {
                ans.push_back(cnt);
                continue;
            }
            grid[i][j] = 1;
            ++cnt;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && find(x * n + y) != find(i * n + j)) {
                    p[find(x * n + y)] = find(i * n + j);
                    --cnt;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};