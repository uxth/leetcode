/*

Description
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won’t stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.

Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using ‘u’, ‘d’, ‘l’ and ‘r’. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output “impossible”.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.

Example 1:

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (0, 1)

Output: "lul"

Explanation: There are two shortest ways for the ball to drop into the hole.
The first way is left -> up -> left, represented by "lul".
The second way is up -> left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".
Image text

Example 2:

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (3, 0)

Output: "impossible"

Explanation: The ball cannot reach the hole.
Image text

Note:

There is only one ball and one hole in the maze.
Both the ball and hole exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and the width and the height of the maze won’t exceed 30.
Solution
Initialize the distances to INFINITY for all positions except start, which has distance 0. Initialize the paths for all positions to null. Since the shortest distance is required, use priority queue during the search. Starting from start, each time obtain all possible positions the ball can reach and stop at, update the shortest distances and paths for such positions, and then do further search from the new positions. If the ball can reach hole, update the shortest distance and the lexicographically smallest path for hole. After all possible positions are visited, the shortest distances possible and corresponding paths are also obtained. Return the path to reach hole, which is the string of directions if hole can be reached, or “impossible” otherwise.

*/

// OJ: https://leetcode.com/problems/the-maze-iii/
// Time: O((MN)^2log(MN))
// Space: O((MN)^2)
class Solution {
    typedef tuple<int, string, int, int> item; // distance, instruction, x, y
public:
    string findShortestWay(vector<vector<int>>& A, vector<int>& ball, vector<int>& hole) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };
        string chars = "dlru";
        vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
        dist[ball[0]][ball[1]] = 0;
        vector<vector<string>> ins(M, vector<string>(N));
        priority_queue<item, vector<item>, greater<>> pq;
        pq.push({0, "", ball[0], ball[1]});
        while (pq.size()) {
            auto [cost, inst, x, y] = pq.top();
            pq.pop();
            if (x == hole[0] && y == hole[1]) return inst;
            if (cost > dist[x][y]) continue;
            for (int i = 0; i < 4; ++i) {
                auto [dx, dy] = dirs[i];
                int a = x + dx, b = y + dy, step = 1;
                while (a >= 0 && a < M && b >= 0 && b < N && A[a][b] == 0 && (a != hole[0] || b != hole[1])) a += dx, b += dy, ++step;
                if (a != hole[0] || b != hole[1]) a -= dx, b -= dy, --step;
                if (a == x && b == y) continue;
                int newCost = cost + step;
                auto newInst = inst + chars[i];
                if (dist[a][b] > newCost) {
                    dist[a][b] = newCost;
                    ins[a][b] = newInst;
                    pq.push({newCost, newInst, a, b});
                } else if (dist[a][b] == newCost && (ins[a][b].empty() || newInst < ins[a][b])) {
                    ins[a][b] = newInst;
                    pq.push({newCost, newInst, a, b});
                } 
            }
        }
        return "impossible";
    }
};