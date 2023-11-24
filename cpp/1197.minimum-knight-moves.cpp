/*

Description
In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Image text

Return the minimum number of steps needed to move the knight to the square [x, y]. It is guaranteed the answer exists.

Example 1:

Input: x = 2, y = 1

Output: 1

Explanation: [0, 0] → [2, 1]

Example 2:

Input: x = 5, y = 5

Output: 4

Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]

Constraints:

|x| + |y| <= 300
Solution
According to the constraint, the size of the chess board is limited, so limit the chess board size to some smaller value. For example, suppose the chess board is 800 * 800, and the knight is initially at [400, 400]. The square [x, y] is adjusted to [x + 400, y + 400] accordingly.

Simply use breadth first search. A knight has at most 8 possible moves, so for each possible move, check whether the knight is still in the chess board after the move, and add the next square to the queue if it is still in the chess board. In this way, the search space can be reduced significantly.

Once the (updated) square [x, y] is reached, return the steps to reach the square, which is guaranteed to be the minimum number of steps.


*/

// OJ: https://leetcode.com/problems/minimum-knight-moves/
// Time: O(XY)
// Space: O(XY)
class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        queue<pair<int, int>> q;
        set<pair<int, int>> s;
        q.emplace(0, 0);
        s.emplace(0, 0);
        int ans = 0, dirs[8][2] = { {1, 2}, {1,-2}, {2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1} };
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [a, b] = q.front();
                q.pop();
                if (a == x && b == y) return ans;
                for (auto &[dx, dy] : dirs) {
                    pair<int, int> next = {a + dx, b + dy};
                    if (abs(next.first) + abs(next.second) > 300 || next.first < -1 || next.second < -1 || s.count(next)) continue;
                    s.insert(next);
                    q.push(next);
                }
            }
            ++ans;
        }
        return 0;
    }
};