/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 *
 * https://leetcode.com/problems/swim-in-rising-water/description/
 *
 * algorithms
 * Hard (53.01%)
 * Likes:    607
 * Dislikes: 55
 * Total Accepted:    25.1K
 * Total Submissions: 47.2K
 * Testcase Example:  '[[0,2],[1,3]]'
 *
 * On an N x N grid, each square grid[i][j] represents the elevation at that
 * point (i,j).
 * 
 * Now rain starts to fall. At time t, the depth of the water everywhere is t.
 * You can swim from a square to another 4-directionally adjacent square if and
 * only if the elevation of both squares individually are at most t. You can
 * swim infinite distance in zero time. Of course, you must stay within the
 * boundaries of the grid during your swim.
 * 
 * You start at the top left square (0, 0). What is the least time until you
 * can reach the bottom right square (N-1, N-1)?
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,2],[1,3]]
 * Output: 3
 * Explanation:
 * At time 0, you are in grid location (0, 0).
 * You cannot go anywhere else because 4-directionally adjacent neighbors have
 * a higher elevation than t = 0.
 * 
 * You cannot reach point (1, 1) until time 3.
 * When the depth of water is 3, we can swim anywhere inside the grid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output: 16
 * Explanation:
 * ⁠0  1  2  3  4
 * 24 23 22 21  5
 * 12 13 14 15 16
 * 11 17 18 19 20
 * 10  9  8  7  6
 * 
 * The final route is marked in bold.
 * We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= N <= 50.
 * grid[i][j] is a permutation of [0, ..., N*N - 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // struct T {
    //     int t, x, y;
    //     T(int a, int b, int c) : t (a), x (b), y (c){}
    //     bool operator< (const T &d) const {return t > d.t;}
    // };

    // int swimInWater(vector<vector<int>>& grid) {
    //     int N = grid.size (), res = 0;
    //     priority_queue<T> pq;
    //     pq.push(T(grid[0][0], 0, 0));
    //     vector<vector<int>> seen(N, vector<int>(N, 0));
    //     seen[0][0] = 1;
    //     static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

    //     while (true) {
    //         auto p = pq.top ();
    //         pq.pop ();
    //         res = max(res, p.t);
    //         if (p.x == N - 1 && p.y == N - 1) return res;
    //         for (auto& d : dir) {
    //             int i = p.x + d[0], j = p.y + d[1];
    //             if (i >= 0 && i < N && j >= 0 && j < N && !seen[i][j]) {
    //                 seen[i][j] = 1;
    //                 pq.push (T(grid[i][j], i, j));
    //             }
    //         }
    //     }
    // }

    ///////////////////////////////////
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
    vector<pair<int,int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> open;
        open.push({grid[0][0], {0,0}});
        vector<vector<bool>> closed(n, vector<bool>(n));
        int res=grid[0][0];
        while(!open.empty())
        {
            while(open.top().first <= res)
            {
                int hight = open.top().first;
                int y = open.top().second.first;
                int x = open.top().second.second;
                open.pop();
                res = max(res, hight);
                if(y==n-1&&x==n-1) return res;
                if(closed[y][x]) continue;
                closed[y][x]=true;
                for(auto& d : dirs)
                {
                    int i = d.first + y;
                    int j = d.second + x;
                    if(i<0||j<0||i>=n||j>=n) continue;
                    open.push({grid[i][j], {i,j}});
                }
            }
            res = open.top().first;
        }
        return res;
    }
};
// @lc code=end

