/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 *
 * https://leetcode.com/problems/binary-trees-with-factors/description/
 *
 * algorithms
 * Medium (43.66%)
 * Likes:    3245
 * Dislikes: 248
 * Total Accepted:    144.9K
 * Total Submissions: 273.5K
 * Testcase Example:  '[2,4]'
 *
 * Given an array of unique integers, arr, where each integer arr[i] is
 * strictly greater than 1.
 * 
 * We make a binary tree using these integers, and each number may be used for
 * any number of times. Each non-leaf node's value should be equal to the
 * product of the values of its children.
 * 
 * Return the number of binary trees we can make. The answer may be too large
 * so return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,4]
 * Output: 3
 * Explanation: We can make these trees: [2], [4], [4, 2, 2]
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,4,5,10]
 * Output: 7
 * Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10,
 * 2, 5], [10, 5, 2].
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * 2 <= arr[i] <= 10^9
 * All the values of arr are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1e9+7;
        sort(arr.begin(), arr.end()); // Sort the array.

        unordered_map<int, long long> dp; // Use a map to store the number of trees for each value.

        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1; // A single node tree with the value arr[i].
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) { // If arr[j] is a factor of arr[i].
                    int factor = arr[i] / arr[j];
                    if (dp.count(factor)) {
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[factor]) % MOD;
                    }
                }
            }
        }

        long long result = 0;
        for (auto& entry : dp) {
            result = (result + entry.second) % MOD;
        }

        return static_cast<int>(result);        
    }
};
// @lc code=end

