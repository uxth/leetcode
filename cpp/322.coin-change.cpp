/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (35.44%)
 * Likes:    5321
 * Dislikes: 161
 * Total Accepted:    500.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: coins = [1], amount = 1
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: coins = [1], amount = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int bfs(vector<int>& coins, int amount)
    // {
    //     queue<long> q;
    //     q.push(0);
    //     int res = 0;
    //     while(!q.empty())
    //     {
    //         int size = q.size();
    //         while(size--)
    //         {
    //             auto f = q.front(); q.pop();
    //             if(f == amount) return res;
    //             for(int c : coins)
    //             {
    //                 if(f+c>amount) continue;
    //                 q.push(c+f);
    //             }
    //         }
    //         res++;
    //     }
    //     return -1;
        
    // }
    int dynamicprogramming(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=amount; ++i)
        {
            for(int c : coins)
            {
                if(i-c>=0 && dp[i-c] != INT_MAX)
                {
                    dp[i]=min(dp[i], 1+dp[i-c]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    // int helper(vector<int>& coins, int amount, unordered_map<int,int>& dp)
    // {
    //     if(amount <= 0) return 0;
    //     if(dp.count(amount)) return dp[amount];

    //     int data = INT_MAX;
    //     for(int c : coins)
    //         if(amount>c)
    //         {
    //             int d = helper(coins, amount-c, dp);
    //             if(d!=-1) data = min(data, 1 + d);
    //         }
    //     return data == INT_MAX ? -1 : dp[amount] = data;
    // }
    // int dfs(vector<int>& coins, int amount)
    // {
    //     unordered_map<int,int> dp;
    //     for(int c : coins) dp[c]=1;
    //     return helper(coins, amount ,dp);
    // }
    int coinChange(vector<int>& coins, int amount) {
        // return bfs(coins, amount);
        return dynamicprogramming(coins, amount);
        // return dfs(coins, amount);
    }
};
// @lc code=end
// [2]\n3
// [1]\n0
// [1]\n2
// [1,2147483647]\n2
// [1,2,5]\n100