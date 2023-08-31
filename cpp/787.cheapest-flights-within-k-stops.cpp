/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium (39.30%)
 * Likes:    2317
 * Dislikes: 77
 * Total Accepted:    123K
 * Total Submissions: 313.1K
 * Testcase Example:  '3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n1'
 *
 * There are n cities connected by m flights. Each flight starts from city u
 * and arrives at v with a price w.
 * 
 * Now given all the cities and flights, together with starting city src and
 * the destination dst, your task is to find the cheapest price from src to dst
 * with up to k stops. If there is no such route, output -1.
 * 
 * 
 * Example 1:
 * Input: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 1
 * Output: 200
 * Explanation: 
 * The graph looks like this:
 * 
 * 
 * The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as
 * marked red in the picture.
 * 
 * 
 * Example 2:
 * Input: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 0
 * Output: 500
 * Explanation: 
 * The graph looks like this:
 * 
 * 
 * The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as
 * marked blue in the picture.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes n will be in range [1, 100], with nodes labeled from 0
 * to n - 1.
 * The size of flights will be in range [0, n * (n - 1) / 2].
 * The format of each flight will be (src, dst, price).
 * The price of each flight will be in the range [1, 10000].
 * k is in the range of [0, n - 1].
 * There will not be any duplicated flights or self cycles.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    //     unordered_map<int,vector<pair<int,int>>> m;
    //     for(auto& f : flights)
    //     {
    //         m[f[0]].push_back({f[1], f[2]});
    //         // m[f[1]].push_back({f[0], f[2]});
    //     }
    //     queue<pair<int,int>> q;
    //     q.push({src, 0});
    //     vector<int> costs(n, INT_MAX);
    //     costs[src] = 0;
    //     K++;
    //     while(K--)
    //     {
    //         int size = q.size();
    //         while(size--)
    //         {
    //             int node = q.front().first;
    //             int cost = q.front().second;
    //             q.pop();
    //             for(auto& [next, price] : m[node])
    //             {
    //                 if(costs[next] > price+cost)
    //                 {
    //                     costs[next] = price+cost;
    //                     q.push({next, costs[next]});
    //                 }
    //             }
    //         }
    //     }
    //     return costs[dst] == INT_MAX ? -1 : costs[dst];
    // }


        
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {        
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        //dp[i][j] = Dist to reach j using atmost i edges from src
        for(int i = 0; i <= K+1; i++)
            dp[i][src] = 0; // Dist to reach src always zero
        
        for(int i = 1; i <= K+1; i++)
        {
            for(auto &f: flights)
            {
                //Using indegree
                int from = f[0];
                int to = f[1];
                int cost = f[2];
                
                if(dp[i-1][from] != INT_MAX)
                    dp[i][to] = min(dp[i][to], dp[i-1][from] + cost);
            }
        }
        
        return (dp[K+1][dst] == INT_MAX)? -1: dp[K+1][dst];
    }
};
// @lc code=end
// 3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n0
// 5\n[[4,1,1],[1,2,3],[0,3,2],[0,4,10],[3,1,1],[1,4,3]]\n2\n1\n1