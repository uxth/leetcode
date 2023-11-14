/*

Question
Formatted question description: https://leetcode.ca/all/276.html

You are painting a fence of n posts with k different colors. You must paint the posts following these rules:

Every post must be painted exactly one color.
There cannot be three or more consecutive posts with the same color.
Given the two integers n and k, return the number of ways you can paint the fence.

 

Example 1:



Input: n = 3, k = 2
Output: 6
Explanation: All the possibilities are shown.
Note that painting all the posts red or all the posts green is invalid because there cannot be three posts in a row with the same color.
Example 2:

Input: n = 1, k = 1
Output: 1
Example 3:

Input: n = 7, k = 2
Output: 42
 

Constraints:

1 <= n <= 50
1 <= k <= 105
The testcases are generated such that the answer is in the range [0, 231 - 1] for the given n and k.
Algorithm
If either n == 0 or k == 0, then it is impossible to paint the fence according to the requirement, so return 0.

Use dynamic programming. Create a 2D array dp with n rows and 2 columns, where

dp[i][1] represents the number of ways to paint the fence’s first i + 1 posts while the i-th post has the same color as its previous post,
and dp[i][0] represents the number of ways to paint the fence’s first i + 1 posts while the i-th post doesn’t have the same color as its previous post.
Obviously, dp[0][0] = 0 and dp[0][1] = k. For i > 0, dp[i][0] = dp[i - 1][1] since the current post has the same color as the previous post, and dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) * (k - 1) since to select a color different to the previous post, there are k - 1 selections.

Finally, return dp[n - 1][0] + dp[n - 1][1].
*/

// OJ: https://leetcode.com/problems/paint-fence/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numWays(int n, int k) {
        if (k == 1 && n >= 3) return 0;
        int dp[2] = {k, 0};
        for (int i = 1; i < n; ++i) {
            int next[2] = {(k - 1) * (dp[0] + dp[1]), dp[0]};
            swap(next, dp);
        }
        return dp[0] + dp[1];
    }
};