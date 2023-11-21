/*

Description
Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.

Example:

Input: [1,2,1,2,1,2,1]

Output: True

Explanation:

i = 1, j = 3, k = 5.

sum(0, i - 1) = sum(0, 0) = 1

sum(i + 1, j - 1) = sum(2, 2) = 1

sum(j + 1, k - 1) = sum(4, 4) = 1

sum(k + 1, n - 1) = sum(6, 6) = 1

Note:

1 <= n <= 2000.
Elements in the given array will be in range [-1,000,000, 1,000,000].
Solution
Several solutions exist for this problem. One solution is to use dynamic programming.

Create a 2D array dp of type Set<Integer> with nums.length rows and 5 columns, where dp[i][j] represents the possible sums when the subarray nums[0..i] is split into j parts. For 0 <= i < nums.length, dp[i][1] contains the value that equals the sum of all the elements in nums[0..i].

Then for 2 <= i < nums.length and for 2 <= j <= 4, loop over k from i to 2, and let sum be the sum of all the elements in nums[k..i]. If dp[k - 2][j - 1] contains sum, then add sum to dp[i][j].

Finally, return true if and only if dp[nums.length - 1][4] is not empty.

*/

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + nums[i];
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> seen;
            for (int i = 1; i < j - 1; ++i)
                if (s[i] == s[j] - s[i + 1])
                    seen.insert(s[i]);
            for (int k = j + 2; k < n - 1; ++k)
                if (s[n] - s[k + 1] == s[k] - s[j + 1] && seen.count(s[n] - s[k + 1]))
                    return true;
        }
        return false;
    }

};