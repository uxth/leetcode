/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 *
 * https://leetcode.com/problems/matrix-cells-in-distance-order/description/
 *
 * algorithms
 * Easy (65.66%)
 * Likes:    228
 * Dislikes: 102
 * Total Accepted:    24.1K
 * Total Submissions: 36.7K
 * Testcase Example:  '1\n2\n0\n0'
 *
 * We are given a matrix with R rows and C columns has cells with integer
 * coordinates (r, c), where 0 <= r < R and 0 <= c < C.
 * 
 * Additionally, we are given a cell in that matrix with coordinates (r0, c0).
 * 
 * Return the coordinates of all cells in the matrix, sorted by their distance
 * from (r0, c0) from smallest distance to largest distance.  Here, the
 * distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance,
 * |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that
 * satisfies this condition.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: R = 1, C = 2, r0 = 0, c0 = 0
 * Output: [[0,0],[0,1]]
 * Explanation: The distances from (r0, c0) to other cells are: [0,1]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: R = 2, C = 2, r0 = 0, c0 = 1
 * Output: [[0,1],[0,0],[1,1],[1,0]]
 * Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
 * The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: R = 2, C = 3, r0 = 1, c0 = 2
 * Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
 * Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
 * There are other answers that would also be accepted as correct, such as
 * [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= R <= 100
 * 1 <= C <= 100
 * 0 <= r0 < R
 * 0 <= c0 < C
 * 
 * 
 * 
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
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    // vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    //     vector<vector<int>> res(R*C, vector<int>(2));
    //     int k = 0;
    //     vector<vector<bool>> visited(R, vector<bool>(C, false));
    //     queue<pair<int,int>> q;
    //     q.push({r0,c0});
    //     while(k<res.size())
    //     {
    //         int size = q.size();
    //         while(size--)
    //         {
    //             int y = q.front().first; int x = q.front().second;
    //             q.pop();
    //             if(visited[y][x]) continue;
    //             visited[y][x] = true;
    //             res[k++] = {y,x};
    //             for(auto& d : dir)
    //             {
    //                 int i = y + d.first; int j = x + d.second;
    //                 if(i<0||j<0||i>=R||j>=C) continue;
    //                 q.push({i,j});
    //             }
    //         }
    //     }
    //     return res;
    // }

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
    {
        map<int, vector<vector<int>>> m;
        for(int i=0;i<R; ++i) for(int j=0;j<C; ++j)
            m[abs(i-r0)+abs(j-c0)].push_back({i,j});
        vector<vector<int>> res;
        for(auto& [dis, data] : m) res.insert(res.end(), data.begin(), data.end());
        return res;
    }
};
// @lc code=end

// 2\n3\n1\n2