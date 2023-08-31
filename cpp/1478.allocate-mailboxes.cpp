/*
 * @lc app=leetcode id=1478 lang=cpp
 *
 * [1478] Allocate Mailboxes
 *
 * https://leetcode.com/problems/allocate-mailboxes/description/
 *
 * algorithms
 * Hard (55.00%)
 * Likes:    263
 * Dislikes: 4
 * Total Accepted:    4.5K
 * Total Submissions: 8.2K
 * Testcase Example:  '[1,4,8,10,20]\n3'
 *
 * Given the array houses and an integer k. where houses[i] is the location of
 * the ith house along a street, your task is to allocate k mailboxes in the
 * street.
 * 
 * Return the minimum total distance between each house and its nearest
 * mailbox.
 * 
 * The answer is guaranteed to fit in a 32-bit signed integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: houses = [1,4,8,10,20], k = 3
 * Output: 5
 * Explanation: Allocate mailboxes in position 3, 9 and 20.
 * Minimum total distance from each houses to nearest mailboxes is |3-1| +
 * |4-3| + |9-8| + |10-9| + |20-20| = 5 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: houses = [2,3,5,12,18], k = 2
 * Output: 9
 * Explanation: Allocate mailboxes in position 3 and 14.
 * Minimum total distance from each houses to nearest mailboxes is |2-3| +
 * |3-3| + |5-3| + |12-14| + |18-14| = 9.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: houses = [7,4,6,1], k = 1
 * Output: 8
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: houses = [3,6,14,10], k = 4
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == houses.length
 * 1 <= n <= 100
 * 1 <= houses[i] <= 10^4
 * 1 <= k <= n
 * Array houses contain unique integers.
 * 
 */

// @lc code=start
#define MAX 100
#define INF 1000000
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<int>> costs(n, vector<int>(n, 0));
        vector<vector<int>> dp(k+1, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int t = i; t <= j; t++)
                    costs[i][j] += abs(houses[(i + j) / 2] - houses[t]);
        return dfs(houses, k, 0, costs, dp);
    }
    int dfs(vector<int>& houses, int k, int i, vector<vector<int>>& costs, vector<vector<int>>& dp) {
        if (k == 0 && i == houses.size()) return 0;
        if (k == 0 || i == houses.size()) return INF;
        if (dp[k][i] != -1) return dp[k][i];
		int ans = INF;
        for (int j = i; j < houses.size(); j++)
            ans = min(ans, costs[i][j] + dfs(houses, k-1, j + 1, costs, dp));
        return dp[k][i] = ans;
    }
};
// @lc code=end
// [2,3,5,12,18]\n2
// [7,4,6,1]\n1
// [3,6,14,10]\n4
// [178,40,129,145,189,134,68,84,67,162,73,80,133,101,71,6,165,53,126,180,24,1,119,196,65,153]\n9