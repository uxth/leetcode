/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (44.93%)
 * Likes:    1894
 * Dislikes: 233
 * Total Accepted:    110.9K
 * Total Submissions: 246.4K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        unordered_map<int, unordered_map<int,int>> graph;
        for(auto& t : times)
            graph[t[0]][t[1]] = t[2];
        queue<int> q;
        q.push(K);
        vector<int> cost(N+1, INT_MAX);
        cost[K]=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto& n : graph[node])
            {
                if(cost[node]+n.second < cost[n.first])
                {
                    cost[n.first] = cost[node]+n.second;
                    q.push(n.first);
                }
            }
        }
        int res = 0;
        for(int i=1; i<=N; ++i)
        {
            if(cost[i]==INT_MAX) return -1;
            res = max(res, cost[i]);
        }
        return res;
    }

};
// @lc code=end
// [[1,2,1]]\n2\n2
// [[1,2,1],[2,3,2],[1,3,4]]\n3\n1
// [[4,2,76],[1,3,79],[3,1,81],[4,3,30],[2,1,47],[1,5,61],[1,4,99],[3,4,68],[3,5,46],[4,1,6],[5,4,7],[5,3,44],[4,5,19],[2,3,13],[3,2,18],[1,2,0],[5,1,25],[2,5,58],[2,4,77],[5,2,74]]\n5\n3
