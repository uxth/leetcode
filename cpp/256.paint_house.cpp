/*

Question
Formatted question description: https://leetcode.ca/all/256.html

There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.

 

Example 1:

Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.
Example 2:

Input: costs = [[7,6,2]]
Output: 2
 

Constraints:

costs.length == n
costs[i].length == 3
1 <= n <= 100
1 <= costs[i][j] <= 20
Algorithm
Two-dimensional dynamic array dp, where dp[i][j] represents the minimum cost of brushing to the i+1th house with color j, and the state transition equation is:

dp[i][j] = cost[i][j] + min(dp[i-1][(j + 1)% 3], dp[i-1][(j + 2)% 3])
*/

// OJ: https://leetcode.com/problems/paint-house/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        for (int i = 1; i < costs.size(); ++i) {
            for (int j = 0; j < 3; ++j)
                costs[i][j] += min(costs[i - 1][(j + 1) % 3], costs[i - 1][(j + 2) % 3]);
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};