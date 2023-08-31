/*

On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the Manhattan distances between each worker and their assigned bike is minimized.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.

Example 1:



Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: 6
Explanation: 
We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of both assignments is 3, so the output is 6.
Example 2:



Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: 4
Explanation: 
We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the Manhattan distances as 4.
Note:

0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000
All worker and bike locations are distinct.
1 <= workers.length <= bikes.length <= 10

*/

class Solution {
private:
    int dict(const vector<int>& worker, const vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<int>> dp(workers.size(), vector<int>(bikes.size(), 0));
        for (auto i = 0; i < workers.size(); ++i) {
            for (auto j = 0; j < bikes.size(); ++j) {
                dp[i][j] = dict(workers[i], bikes[j]);
            }
        }
        int res = INT_MAX;
        vector<int> memo(1 << bikes.size(), 0);
        return permRes(dp, memo, 0, 0);
    }
    int permRes(const vector<vector<int>>& dp, 
                vector<int>& memo, 
                int state, 
                int idx) 
    {
        if (idx == dp.size()) {
            return 0;
        }
        if (memo[state] != 0) {
            return memo[state];
        }
        int tmp = INT_MAX;
        for (auto j = 0; j < dp[0].size(); j++) {
            if ((state & (1 << j)) == 0) {
                tmp = min(tmp, dp[idx][j] + permRes(dp, memo, state | (1<<j), idx + 1));
            }
        }
        memo[state] = tmp;
        return memo[state];
    }
};