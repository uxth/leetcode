/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 *
 * https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
 *
 * algorithms
 * Hard (49.15%)
 * Likes:    1732
 * Dislikes: 199
 * Total Accepted:    52.7K
 * Total Submissions: 98.2K
 * Testcase Example:  '[2,1,3]'
 *
 * Given an array nums that represents a permutation of integers from 1 to n.
 * We are going to construct a binary search tree (BST) by inserting the
 * elements of nums in order into an initially empty BST. Find the number of
 * different ways to reorder nums so that the constructed BST is identical to
 * that formed from the original array nums.
 *
 *
 * For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left
 * child, and 3 as a right child. The array [2,3,1] also yields the same BST
 * but [3,2,1] yields a different BST.
 *
 *
 * Return the number of ways to reorder nums such that the BST formed is
 * identical to the original BST formed from nums.
 *
 * Since the answer may be very large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,1,3]
 * Output: 1
 * Explanation: We can reorder nums to be [2,3,1] which will yield the same
 * BST. There are no other ways to reorder nums which will yield the same
 * BST.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,4,5,1,2]
 * Output: 5
 * Explanation: The following 5 arrays will yield the same BST:
 * [3,1,2,4,5]
 * [3,1,4,2,5]
 * [3,1,4,5,2]
 * [3,4,1,2,5]
 * [3,4,1,5,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 0
 * Explanation: There are no other orderings of nums that will yield the same
 * BST.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= nums.length
 * All integers in nums are distinct.
 *
 *
 */

// @lc code=start
class Solution
{
    const int mod = 1e9 + 7;

public:
    int PascalTriangle(vector<int> &nums){
        // Different permutation that yield same bst as given
        // T.C -> O(N^2)[RECURSION]+O(N^2) [PASCAL]
        // S.C -> O(N^2)[D.P]
        int n = nums.size();
        vector<vector<int>> dp(n + 1);
        for (int i = 0; i <= n; i++){
            dp[i] = vector<int>(i + 1, 1); // initially all 1
            // Now Apply combination logic of adding prev_row and prev_col
            for (int j = 1; j < i; j++){
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
        return dfs(nums, dp) - 1;
    }
    long long dfs(vector<int> &nums, vector<vector<int>> &dp){
        vector<int> leftSubTree, rightSubTree;
        int n = nums.size();

        // 1 COMBINATION OF BST POSSIBLE
        if (n < 3)
            return 1;

        // FIND LEFT AND RIGHT SUBTREE FOR ROOT I.E nums[0]
        for (int i = 1; i < n; i++){
            if (nums[i] >= nums[0])
                rightSubTree.push_back(nums[i]);
            if (nums[i] < nums[0])
                leftSubTree.push_back(nums[i]);
        }

        long long left = dfs(leftSubTree, dp) % mod;
        long long right = dfs(rightSubTree, dp) % mod;
        return ((left * dp[n - 1][leftSubTree.size()] % mod) * right) % mod;
    }

    int numOfWays(vector<int> &nums){
        return PascalTriangle(nums);
    }
};
// @lc code=end
/*
[3,4,5,1,2]
[1,2,3]
[4,5,1,6,2,3]
[3,1,2,5,4,6]
[3,4,5,1,2]
*/
