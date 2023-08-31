/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 *
 * https://leetcode.com/problems/last-stone-weight-ii/description/
 *
 * algorithms
 * Medium (44.08%)
 * Likes:    785
 * Dislikes: 30
 * Total Accepted:    20.4K
 * Total Submissions: 46.2K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * We have a collection of rocks, each rock has a positive integer weight.
 * 
 * Each turn, we choose any two rocks and smash them together.  Suppose the
 * stones have weights x and y with x <= y.  The result of this smash is:
 * 
 * 
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of
 * weight y has new weight y-x.
 * 
 * 
 * At the end, there is at most 1 stone left.  Return the smallest possible
 * weight of this stone (the weight is 0 if there are no stones left.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,7,4,1,8,1]
 * Output: 1
 * Explanation: 
 * We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
 * we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
 * we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 * we can combine 1 and 1 to get 0 so the array converts to [1] then that's the
 * optimal value.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 100
 * 
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n + 1,vector<int>(sum / 2 + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum / 2; j++) {
                if (j >= stones[i - 1]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return sum - 2 * dp[n][sum / 2];
    }

    // int lastStoneWeightII(vector<int>& stones) {
    //     sort(stones.begin(),stones.end());
    //     int sum=accumulate(stones.begin(), stones.end(), 0);
    //     vector<vector<bool>> dp(stones.size()+1,vector<bool>(2*sum+1,false));
    //     dp[0][sum]=true;
    //     int ans=INT_MAX;
    //     for(int i=1;i<dp.size();i++)
    //     {
    //         for(int j=0;j<dp[0].size();j++)
    //         {
    //             if(j+stones[i-1]<dp[0].size() && dp[i-1][j+stones[i-1]]==true)
    //                 dp[i][j]=true;
    //             if(j-stones[i-1]>=0 && dp[i-1][j-stones[i-1]]==true)
    //                 dp[i][j]=true;
    //             if(i==dp.size()-1 && dp[i][j]==true)
    //             {
    //                 ans=min(ans,abs(j-sum));
    //             }
    //         }
    //     }
    //     return ans;

    // }
};
// @lc code=end
// [1,3,4,3,5,4]
// [31,26,33,21,40]