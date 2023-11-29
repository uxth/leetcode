/*
 * @lc app=leetcode id=1263 lang=cpp
 *
 * [1263] Minimum Moves to Move a Box to Their Target Location
 *
 * https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/description/
 *
 * algorithms
 * Hard (41.38%)
 * Likes:    214
 * Dislikes: 8
 * Total Accepted:    4.5K
 * Total Submissions: 10.8K
 * Testcase Example:  '[["#","#","#","#","#","#"],
 *                      ["#","T","#","#","#","#"],
 *                      ["#",".",".","B",".","#"],
 *                      ["#",".","#","#",".","#"],
 *                      ["#",".",".",".","S","#"],
 *                      ["#","#","#","#","#","#"]]'
 *
 * Storekeeper is a game in which the player pushes boxes around in a warehouse
 * trying to get them to target locations.
 * 
 * The game is represented by a grid of size m x n, where each element is a
 * wall, floor, or a box.
 * 
 * Your task is move the box 'B' to the target position 'T' under the following
 * rules:
 * 
 * 
 * Player is represented by character 'S' and can move up, down, left, right in
 * the grid if it is a floor (empy cell).
 * Floor is represented by character '.' that means free cell to walk.
 * Wall is represented by character '#' that means obstacle  (impossible to
 * walk there). 
 * There is only one box 'B' and one target cell 'T' in the grid.
 * The box can be moved to an adjacent free cell by standing next to the box
 * and then moving in the direction of the box. This is a push.
 * The player cannot walk through the box.
 * 
 * 
 * Return the minimum number of pushes to move the box to the target. If there
 * is no way to reach the target, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid = [["#","#","#","#","#","#"],
 * ⁠               ["#","T","#","#","#","#"],
 *                ["#",".",".","B",".","#"],
 *                ["#",".","#","#",".","#"],
 *                ["#",".",".",".","S","#"],
 *                ["#","#","#","#","#","#"]]
 * Output: 3
 * Explanation: We return only the number of times the box is pushed.
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [["#","#","#","#","#","#"],
 * ⁠               ["#","T","#","#","#","#"],
 *                ["#",".",".","B",".","#"],
 *                ["#","#","#","#",".","#"],
 *                ["#",".",".",".","S","#"],
 *                ["#","#","#","#","#","#"]]
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [["#","#","#","#","#","#"],
 *                ["#","T",".",".","#","#"],
 *                ["#",".","#","B",".","#"],
 *                ["#",".",".",".",".","#"],
 *                ["#",".",".",".","S","#"],
 *                ["#","#","#","#","#","#"]]
 * Output: 5
 * Explanation:  push the box down, left, left, up and up.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: grid = [["#","#","#","#","#","#","#"],
 *                ["#","S","#",".","B","T","#"],
 *                ["#","#","#","#","#","#","#"]]
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m <= 20
 * 1 <= n <= 20
 * grid contains only characters '.', '#',  'S' , 'T', or 'B'.
 * There is only one character 'S', 'B' and 'T' in the grid.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };

    struct pos
    {
        pos(int by, int bx, int py, int px, int s): boxy(by), boxx(bx), pushery(py), pusherx(px), step(s) {}
        // pos(const pos& p): boxy(p.boxy), boxx(p.boxx), pushery(p.pushery), pusherx(p.pusherx), step(p.step){}
        int boxy, boxx;
        int pushery, pusherx;
        int step;

        bool operator == (const pos& k) const { return k.boxy == boxy && k.boxx == boxx && pushery == k.pushery && pusherx == k.pusherx;}

    };
    struct pos_hash
    {
        size_t operator()(const pos& k) const
        {
            size_t h1 = std::hash<int>()(k.boxy);
            size_t h2 = std::hash<int>()(k.boxx);
            size_t h3 = std::hash<int>()(k.pushery);
            size_t h4 = std::hash<int>()(k.pusherx);
            return h1 ^ h2 ^ h3 ^ h4;
        }
    };
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    bool reachable(vector<vector<char>>& grid, int y, int x, int y0, int x0, int by, int bx)
    {
        if(y==y0 && x==x0) return true;
        int m=grid.size(), n=grid[0].size();
        if(y<0||x<0||y>=m||x>=n) return false;
        if(grid[y][x] == '#') return false;
        queue<pair<int,int>> q;
        q.push({y0, x0});
        unordered_set<pair<int,int>, pair_hash> visited;
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(visited.count({i,j})) continue;
            visited.insert({i,j});
            if(i==y && j == x) return true;
            for(auto& d : dir)
            {
                int nexty = d.first + i;
                int nextx = d.second + j;
                if(nexty<0||nextx<0||nexty>=m||nextx>=n) continue;
                if(grid[nexty][nextx] == '#' || (nexty == by && nextx == bx)) continue;
                q.push({nexty, nextx});
            }
        }
        return false;
    }
    bool moveable(vector<vector<char>>& grid, int y, int x, int pushery, int pusherx, unordered_set<pos, pos_hash>& visited)
    {
        int m=grid.size(), n=grid[0].size();
        if(y<0||x<0||y>=m||x>=n) return false;
        if(visited.count(pos(y, x, pushery, pusherx, 0))) return false;
        if(grid[y][x] == '.' || grid[y][x] == 'T') return true;
        return false;
    }
    int minPushBox(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m=grid.size(), n=grid[0].size();

        pair<int,int> start, box, target;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 'S')
                {
                    grid[i][j] = '.';
                    start.first=i; start.second=j;
                }
                else if(grid[i][j] == 'B')
                {
                    grid[i][j] = '.';
                    box.first=i; box.second=j;
                }
                else if(grid[i][j] == 'T')
                {
                    target.first=i; target.second=j;
                }
            }
        }
        
        unordered_set<pos, pos_hash> visited;
        queue<pos> q;
        q.push(pos(box.first, box.second, start.first, start.second, 0));

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto& f = q.front();
                if(visited.count(f)) {q.pop(); continue;}
                visited.insert(f);
                if(f.boxy == target.first && f.boxx == target.second) return f.step;
                for(auto& d : dir)
                {
                    int movetoy = f.boxy + d.first;
                    int movetox = f.boxx + d.second;
                    if(reachable(grid, f.boxy-d.first, f.boxx-d.second, f.pushery, f.pusherx, f.boxy, f.boxx) && moveable(grid, movetoy, movetox, f.boxy, f.boxx, visited))
                    {
                        q.push(pos(movetoy, movetox, f.boxy, f.boxx, f.step+1));
                    }
                }
                q.pop();
            }
            // cout << endl;
        }
        
        return -1;

    }
};
// @lc code=end

/*
[["#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"]
,["#",".",".",".",".",".",".",".",".",".",".",".","#","#","#","#"]
,["#",".","#","#","#","#",".","#","#","#","#",".","#","#","#","."]
,["#",".",".",".",".",".",".","#","T","#",".",".","#","#","#","."]
,["#",".",".",".","#",".",".",".",".",".",".",".","#","#","#","."]
,["#",".",".",".",".",".","B",".",".",".",".",".","#","#","#","."]
,["#",".","#","#","#","#","#","#","#","#","#",".","#","#","#","."]
,["#",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."]
,["#",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."]
,["#",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."]
,["#",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."]
,["#",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."]
,["#",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."]
,["#",".",".",".",".",".",".",".","S",".",".",".",".",".",".","."]
,["#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"]]


[["#",".",".","#","T","#","#","#","#"]
,["#",".",".","#",".","#",".",".","#"]
,["#",".",".","#",".","#","B",".","#"]
,["#",".",".",".",".",".",".",".","#"]
,["#",".",".",".",".","#",".","S","#"]
,["#",".",".","#",".","#","#","#","#"]]


[["#",".",".","#","#","#","#","#"]
,["#",".",".","T","#",".",".","#"]
,["#",".",".",".","#","B",".","#"]
,["#",".",".",".",".",".",".","#"]
,["#",".",".",".","#",".","S","#"]
,["#",".",".","#","#","#","#","#"]]


[["#","#","#","#","#","#"],
["#","T","#","#","#","#"],
["#",".",".","B",".","#"],
["#","#","#","#",".","#"],
["#",".",".",".","S","#"],
["#","#","#","#","#","#"]]

[["#","#","#","#","#","#"],
["#","T",".",".","#","#"],
["#",".","#","B",".","#"],
["#",".",".",".",".","#"],
["#",".",".",".","S","#"],
["#","#","#","#","#","#"]]
*/