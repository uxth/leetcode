/*
 * @lc app=leetcode id=1442 lang=cpp
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 *
 * https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
 *
 * algorithms
 * Medium (69.35%)
 * Likes:    364
 * Dislikes: 21
 * Total Accepted:    13.5K
 * Total Submissions: 19.2K
 * Testcase Example:  '[2,3,1,6,7]'
 *
 * Given an array of integers arr.
 * 
 * We want to select three indices i, j and k where (0 <= i < j <= k <
 * arr.length).
 * 
 * Let's define a and b as follows:
 * 
 * 
 * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
 * b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
 * 
 * 
 * Note that ^ denotes the bitwise-xor operation.
 * 
 * Return the number of triplets (i, j and k) Where a == b.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,3,1,6,7]
 * Output: 4
 * Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,1,1,1,1]
 * Output: 10
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [2,3]
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [1,3,5,7,9]
 * Output: 3
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [7,11,12,9,5,2,7,17,22]
 * Output: 8
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 300
 * 1 <= arr[i] <= 10^8
 * 
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        for(int i=n-1; i>=0; --i)
        {
            for(int j=i; j<n; ++j)
            {
                dp[i][j] = i==j ? arr[i] : dp[i][j-1] ^ arr[j];
                for(int k=j+1; k<n; ++k)
                    if(dp[i][j] == dp[j+1][k]) res++;
            }
        }
        // for(int i=0; i<n; ++i) {for(int j=0; j<n; ++j) cout << dp[i][j] << " "; cout << endl;}
        return res;
    }
};
// @lc code=end
// [7,11,12,9,5,2,7,17,22]
// [1,3,5,7,9]
// [1,1,1,1,1]