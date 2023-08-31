/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 *
 * https://leetcode.com/problems/course-schedule-iv/description/
 *
 * algorithms
 * Medium (41.73%)
 * Likes:    228
 * Dislikes: 13
 * Total Accepted:    10.4K
 * Total Submissions: 24.6K
 * Testcase Example:  '2\r\n[[1,0]]\r\n[[0,1],[1,0]]\r'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have direct prerequisites, for example, to take course 0
 * you have first to take course 1, which is expressed as a pair: [1,0]
 * 
 * Given the total number of courses n, a list of direct prerequisite pairs and
 * a list of queries pairs.
 * 
 * You should answer for each queries[i] whether the course queries[i][0] is a
 * prerequisite of the course queries[i][1] or not.
 * 
 * Return a list of boolean, the answers to the given queries.
 * 
 * Please note that if course a is a prerequisite of course b and course b is a
 * prerequisite of course c, then, course a is a prerequisite of course c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
 * Output: [false,true]
 * Explanation: course 0 is not a prerequisite of course 1 but the opposite is
 * true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2, prerequisites = [], queries = [[1,0],[0,1]]
 * Output: [false,false]
 * Explanation: There are no prerequisites and each course is independent.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
 * Output: [true,true]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
 * Output: [false,true]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries =
 * [[0,4],[4,0],[1,3],[3,0]]
 * Output: [true,false,true,false]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 100
 * 0 <= prerequisite.length <= (n * (n - 1) / 2)
 * 0 <= prerequisite[i][0], prerequisite[i][1] < n
 * prerequisite[i][0] != prerequisite[i][1]
 * The prerequisites graph has no cycles.
 * The prerequisites graph has no repeated edges.
 * 1 <= queries.length <= 10^4
 * queries[i][0] != queries[i][1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
       vector<bool> ans;
       vector<vector<int>> isReachable(n, vector<int> (n, 0));
       queue<int> q;
	   //adjacency list
        vector<vector<int>> adj(n);
        for(auto &p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }   
		//visited 
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++){
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                 for(int neighbor : adj[node]){
                    if(visited[i][neighbor]) continue;
                    isReachable[i][neighbor]  = 1;
                    visited[i][neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        
        for(auto &q : queries){
            ans.push_back(isReachable[q[0]][q[1]]);
        }      
        return ans;
    }
};
// @lc code=end

//  3\n[[1,2],[2,0]]\n[[1,0],[1,0]]
// 5\n[[3,4],[2,3],[1,2],[0,1]]\n[[0,4],[4,0],[1,3],[3,0]]