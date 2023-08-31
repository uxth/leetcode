/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 *
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 *
 * algorithms
 * Medium (55.28%)
 * Likes:    1069
 * Dislikes: 386
 * Total Accepted:    54.8K
 * Total Submissions: 99.2K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]'
 *
 * On a 2D plane, we place stones at some integer coordinate points.  Each
 * coordinate point may have at most one stone.
 * 
 * Now, a move consists of removing a stone that shares a column or row with
 * another stone on the grid.
 * 
 * What is the largest possible number of moves we can make?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output: 5
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: stones = [[0,0]]
 * Output: 0
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= stones.length <= 1000
 * 0 <= stones[i][j] < 10000
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
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
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_set<pair<int,int>, pair_hash> visited;
        unordered_map<int,vector<int>> row, col;
        for(auto& s : stones)
        {
            row[s[0]].push_back(s[1]);
            col[s[1]].push_back(s[0]);
        }
        int islands = 0;
        for(auto& s : stones)
        {
            if(visited.count({s[0], s[1]})) continue;
            visited.insert({s[0], s[1]});
            queue<pair<int,int>> q;
            q.push({s[0], s[1]});
            while(!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(int c : row[y]) 
                {
                    if(visited.count({y,c})) continue;
                    visited.insert({y,c});
                    q.push({y,c});
                }
                for(int r : col[x])
                {
                    if(visited.count({r,x})) continue;
                    visited.insert({r,x});
                    q.push({r,x});
                }
            }
            islands++;
        }

        return stones.size() - islands;
    }

};
// @lc code=end
// [[0,1],[1,2],[1,3],[3,3],[2,3],[0,2]]
// [[0,1],[0,2],[4,3],[2,4],[0,3],[1,1]]
