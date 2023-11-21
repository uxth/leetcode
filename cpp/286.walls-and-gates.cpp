/*

Question
Formatted question description: https://leetcode.ca/all/286.html

You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

 

Example 1:



Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Example 2:

Input: rooms = [[-1]]
Output: [[-1]]
 

Constraints:

m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 231 - 1.
Algorithm
Search for the position of 0, and every time a 0 is found, start DFS traversal with four adjacent points around it as the starting point, and bring in the depth value 1.

If the value encountered is greater than the current depth value, assign the position value to the current depth value, and start DFS traversal for the four adjacent points of the current point. Note that the depth value needs to be increased by 1.

After the traversal is completed, all positions are updated correctly

*/

// OJ: https://leetcode.com/problems/walls-and-gates/
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& A) {
       int M = A.size(), N = A[0].size(), dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; 
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) q.emplace(i, j);
            }
        }
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] <= A[x][y] + 1) continue; 
                    A[a][b] = A[x][y] + 1;
                    q.emplace(a, b);
                }
            }
        }
    }
};