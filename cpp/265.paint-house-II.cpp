/*

Question
Formatted question description: https://leetcode.ca/all/265.html

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x k cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on...
Return the minimum cost to paint all houses.

 

Example 1:

Input: costs = [[1,5,3],[2,9,4]]
Output: 5
Explanation:
Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
Example 2:

Input: costs = [[1,3],[2,4]]
Output: 5
 

Constraints:

costs.length == n
costs[i].length == k
1 <= n <= 100
2 <= k <= 20
1 <= costs[i][j] <= 20
 

Follow up: Could you solve it in O(nk) runtime?

Algorithm
3 for loops
Use dynamic programming. Create a 2D array dp with n rows and k columns. The element dp[i][j] represents the minimum total cost so far to paint houses 0 to i with the house at index i painted with color j.

For row 0 which corresponds to house 0, dp[0][j] equals costs[0][j]. To get dp[i][j] for i > 0, first find the minimum in row dp[i - 1] except dp[i - 1][j], which is represented as min here, since any two adjacent houses must be painted with different colors, then set dp[i][j] = min + costs[i][j].

Finally, find the minimum element from row dp[n - 1] and return the minimum value, which is the minimum cost to paint all houses.

Follow up: tracking min1 and min2
Finding the minimum value of different colors is not to traverse all the different colors, but to use min1 and min2 to record the smallest and second smallest cost colors

If the current house color is the same as min1, use the value corresponding to min2 to calculate
On the contrary, use the value corresponding to min1. This solution actually includes the method of finding the sub-smallest value
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<int> f = costs[0];
        for (int i = 1; i < n; ++i) {
            vector<int> g = costs[i];
            for (int j = 0; j < k; ++j) {
                int t = INT_MAX;
                for (int h = 0; h < k; ++h) {
                    if (h != j) {
                        t = min(t, f[h]);
                    }
                }
                g[j] += t;
            }
            f = move(g);
        }
        return *min_element(f.begin(), f.end());
    }
};