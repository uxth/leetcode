/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 *
 * https://leetcode.com/problems/bus-routes/description/
 *
 * algorithms
 * Hard (42.56%)
 * Likes:    795
 * Dislikes: 22
 * Total Accepted:    38.3K
 * Total Submissions: 90.1K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * We have a list of bus routes. Each routes[i] is a bus route that the i-th
 * bus repeats forever. For example if routes[0] = [1, 5, 7], this means that
 * the first bus (0-th indexed) travels in the sequence
 * 1->5->7->1->5->7->1->... forever.
 * 
 * We start at bus stop S (initially not on a bus), and we want to go to bus
 * stop T. Travelling by buses only, what is the least number of buses we must
 * take to reach our destination? Return -1 if it is not possible.
 * 
 * 
 * Example:
 * Input: 
 * routes = [[1, 2, 7], [3, 6, 7]]
 * S = 1
 * T = 6
 * Output: 2
 * Explanation: 
 * The best strategy is take the first bus to the bus stop 7, then take the
 * second bus to the bus stop 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 10^5.
 * 0 <= routes[i][j] < 10 ^ 6.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T) return 0;
        unordered_map<int,unordered_set<int>> stop2bus;
        for(int i=0; i<routes.size(); ++i)
        {
            for(int j : routes[i])
            {
                stop2bus[j].insert(i);
            }
        }

        unordered_set<int> visitedstops{S};
        unordered_set<int> visitedbuses;
        queue<int> q;
        q.push(S);
        int res = 1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int f = q.front(); q.pop();
                for(int bus: stop2bus[f])
                {
                    if(visitedbuses.count(bus)) continue;
                    visitedbuses.insert(bus);
                    for(int next : routes[bus])
                    {
                        if(next == T) return res;
                        if(visitedstops.count(next)) continue;
                        visitedstops.insert(next);
                        q.push(next);
                    }
                }
            }
            res++;
        }

        return -1;
    }
};
// @lc code=end

// [[7,12],[4,5,15],[6],[15,19],[9,12,13]]\n15\n12
//[] \n 5 n 5
/*
 

 */