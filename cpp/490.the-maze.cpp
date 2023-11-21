/*

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

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

Output: true

Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false

Explanation: There is no way for the ball to stop at the destination.

 

Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
Companies: Google, Amazon, Facebook

Related Topics: Depth-first Search, Breadth-first Search

Similar Questions:

The Maze III (Hard)
The Maze II (Medium)


Solution 1. BFS
// OJ: https://leetcode.com/problems/the-maze/
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
    int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int hash(vector<int> &p) { return p[0] * 1000 + p[1]; }
    vector<int> go(vector<vector<int>>& maze, int x, int y, int d[2]) {
        int M = maze.size(), N = maze[0].size();
        do {
            x += d[0];
            y += d[1];
        } while (x >= 0 && x < M && y >= 0 && y < N && !maze[x][y]);
        return { x - d[0], y - d[1] };
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<int> q;
        unordered_set<int> seen;
        int s = hash(start);
        q.push(s);
        seen.insert(s);
        while (q.size()) {
            int val = q.front(), x = val / 1000, y = val % 1000;
            q.pop();
            if (x == destination[0] && y == destination[1]) return true;
            for (auto &dir : dirs) {
                auto to = go(maze, x, y, dir);
                int h = hash(to);
                if (seen.find(h) != seen.end()) continue;
                seen.insert(h);
                q.push(h);
            }
        }
        return false;
    }
};

*/


// OJ: https://leetcode.com/problems/the-maze/
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
    int hash(vector<int> &p) { return p[0] * 1000 + p[1]; }
    vector<int> go(vector<vector<int>>& maze, int x, int y, int d[2]) {
        int M = maze.size(), N = maze[0].size();
        do {
            x += d[0];
            y += d[1];
        } while (x >= 0 && x < M && y >= 0 && y < N && !maze[x][y]);
        return { x - d[0], y - d[1] };
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<int> q;
        unordered_set<int> seen;
        int s = hash(start), dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        q.push(s);
        seen.insert(s);
        while (q.size()) {
            int val = q.front(), x = val / 1000, y = val % 1000;
            q.pop();
            if (x == destination[0] && y == destination[1]) return true;
            for (auto &dir : dirs) {
                auto to = go(maze, x, y, dir);
                int h = hash(to);
                if (seen.count(h)) continue;
                seen.insert(h);
                q.push(h);
            }
        }
        return false;
    }
};