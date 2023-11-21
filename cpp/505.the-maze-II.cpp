/*

Description
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won’t stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball’s start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: 12

Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right. The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
Image text

Example 2:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: -1

Explanation: There is no way for the ball to stop at the destination.
Image text

Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won’t exceed 100.
Solution
Initialize the distances to INFINITY for all positions except start, which has distance 0. Since the shortest distance is required, use priority queue during the search. Starting from start, each time obtain all possible positions the ball can reach and stop at, update the shortest distances for such positions, and then do further search from the new positions. If the ball can reach and stop at destination, update the shortest distance for destination. After all possible positions are visited, the shortest distances possible are also obtained. If the shortest distance at destination is not INFINITY, return the distance. Otherwise, the ball never reaches and stops at destination, return -1.

*/

// OJ: https://leetcode.com/problems/the-maze-ii/
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int shortestDistance(vector<vector<int>>& A, vector<int>& S, vector<int>& E) {
        int M = A.size(), N = A[0].size(), step = 0, dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        vector<vector<vector<bool>>> seen(M, vector<vector<bool>>(N, vector<bool>(4))); // (x, y, direction)
        queue<array<int, 3>> q;
        for (int i = 0; i < 4; ++i) {
            seen[S[0]][S[1]][i] = true;
            q.push({S[0], S[1], i});
        }
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y, dir] = q.front();
                q.pop();
                auto &[dx, dy] = dirs[dir];
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= M || ny < 0 || ny >= N || A[nx][ny]) { // The ball hits a wall. We can probe 4 directions
                    if (x == E[0] && y == E[1]) return step; // we can only check (x, y) if we are by a wall
                    for (int d = 0; d < 4; ++d) {
                        if (d == dir) continue;
                        auto &[dx, dy] = dirs[d];
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N || A[nx][ny] || seen[nx][ny][d]) continue;
                        seen[nx][ny][d] = true;
                        q.push({nx, ny, d});
                    }
                } else if (!seen[nx][ny][dir]) { // The ball doesn't hit a wall. We can only move in the same direction.
                    seen[nx][ny][dir] = true;
                    q.push({nx, ny, dir});
                }
            }
            ++step;
        }
        return -1;
    }
};