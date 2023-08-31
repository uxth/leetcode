/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 *
 * https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
 *
 * algorithms
 * Medium (53.12%)
 * Likes:    496
 * Dislikes: 7
 * Total Accepted:    20.3K
 * Total Submissions: 37.8K
 * Testcase Example:  '4\n[[0,1],[0,2],[1,2]]'
 *
 * There are n computers numbered from 0 to n-1 connected by ethernet cables
 * connections forming a network where connections[i] = [a, b] represents a
 * connection between computers a and b. Any computer can reach any other
 * computer directly or indirectly through the network.
 * 
 * Given an initial computer network connections. You can extract certain
 * cables between two directly connected computers, and place them between any
 * pair of disconnected computers to make them directly connected. Return the
 * minimum number of times you need to do this in order to make all the
 * computers connected. If it's not possible, return -1. 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, connections = [[0,1],[0,2],[1,2]]
 * Output: 1
 * Explanation: Remove cable between computer 1 and 2 and place between
 * computers 1 and 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
 * Output: -1
 * Explanation: There are not enough cables.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 1 <= connections.length <= min(n*(n-1)/2, 10^5)
 * connections[i].length == 2
 * 0 <= connections[i][0], connections[i][1] < n
 * connections[i][0] != connections[i][1]
 * There are no repeated connections.
 * No two computers are connected by more than one cable.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int>parent;
    int find(int x) {
        return (parent[x] == x) ? x : find(parent[x]);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int c = connections.size();
        if (n-1 > c) return -1;
        
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < c; i++) {
            int x = find(connections[i][0]);
            int y = find(connections[i][1]);
            if (x != y) parent[y] = x;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        
        return ans-1;
    }
};
// @lc code=end
// 5\n[[0,1],[0,2],[3,4],[2,3]]
// 6\n[[0,1],[0,2],[0,3],[1,2]]
// 100\n[[17,51],[33,83],[53,62],[25,34],[35,90],[29,41],[14,53],[40,84],[41,64],[13,68],[44,85],[57,58],[50,74],[20,69],[15,62],[25,88],[4,56],[37,39],[30,62],[69,79],[33,85],[24,83],[35,77],[2,73],[6,28],[46,98],[11,82],[29,72],[67,71],[12,49],[42,56],[56,65],[40,70],[24,64],[29,51],[20,27],[45,88],[58,92],[60,99],[33,46],[19,69],[33,89],[54,82],[16,50],[35,73],[19,45],[19,72],[1,79],[27,80],[22,41],[52,61],[50,85],[27,45],[4,84],[11,96],[0,99],[29,94],[9,19],[66,99],[20,39],[16,85],[12,27],[16,67],[61,80],[67,83],[16,17],[24,27],[16,25],[41,79],[51,95],[46,47],[27,51],[31,44],[0,69],[61,63],[33,95],[17,88],[70,87],[40,42],[21,42],[67,77],[33,65],[3,25],[39,83],[34,40],[15,79],[30,90],[58,95],[45,56],[37,48],[24,91],[31,93],[83,90],[17,86],[61,65],[15,48],[34,56],[12,26],[39,98],[1,48],[21,76],[72,96],[30,69],[46,80],[6,29],[29,81],[22,77],[85,90],[79,83],[6,26],[33,57],[3,65],[63,84],[77,94],[26,90],[64,77],[0,3],[27,97],[66,89],[18,77],[27,43]]