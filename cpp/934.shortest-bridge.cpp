/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (48.10%)
 * Likes:    860
 * Dislikes: 66
 * Total Accepted:    31.6K
 * Total Submissions: 65.2K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In a given 2D binary array A, there are two islands.  (An island is a
 * 4-directionally connected group of 1s not connected to any other 1s.)
 * 
 * Now, we may change 0s to 1s so as to connect the two islands together to
 * form 1 island.
 * 
 * Return the smallest number of 0s that must be flipped.  (It is guaranteed
 * that the answer is at least 1.)
 * 
 * 
 * Example 1:
 * Input: A = [[0,1],[1,0]]
 * Output: 1
 * Example 2:
 * Input: A = [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * Example 3:
 * Input: A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= A.length == A[0].length <= 100
 * A[i][j] == 0 or A[i][j] == 1
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
    bool dfs(vector<vector<int>>& A, int y, int x, int marker, queue<pair<int,int>>& edge)
    {
        int m = A.size();
        int n = A[0].size();
        if(y<0||x<0||y>=m||x>=n) return true;
        if(A[y][x] != 1) return true;
        A[y][x] = marker;
        bool reachEdge = false;
        for(auto& d : dir)
        {
            reachEdge |= dfs(A, y+d.first, x+d.second, marker, edge);
        }
        if(reachEdge) {edge.push({y,x});}
        return false;
    }
    void findEdge(vector<vector<int>>& A, queue<pair<int,int>>& edge)
    {
        int m = A.size();
        int n = A[0].size();
        int marker = 2;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(A[i][j] == 1)
                {
                    dfs(A, i, j, marker++, edge);
                    return;
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        if(A.empty() || A[0].empty()) return 0;
        int m = A.size();
        int n = A[0].size();
        queue<pair<int,int>> edge;
        int marker = 2;
        unordered_set<pair<int,int>, pair_hash> visited;
        findEdge(A, edge);
        int step = 0;
        while(!edge.empty())
        {
            int size = edge.size();
            while(size--)
            {
                int y = edge.front().first;
                int x = edge.front().second;
                edge.pop();
                for(auto& d : dir)
                {
                    int i = d.first+y;
                    int j = d.second+x;
                    if(i<0||j<0||i>=m||j>=n) continue;
                    if(A[i][j] == 1) return step;
                    if(A[i][j]==0 && visited.count({i, j}) == 0)
                    {
                        visited.insert({i,j});
                        edge.push({i, j});
                    }
                }
            }
            step++;
        }
        return 0;
    }
};
// @lc code=end
// [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]

