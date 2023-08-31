/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Hard (39.10%)
 * Likes:    1994
 * Dislikes: 353
 * Total Accepted:    217.5K
 * Total Submissions: 554.7K
 * Testcase Example:  '3\n3'
 *
 * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * 
 * Example 1:
 * Input: n = 3, k = 3
 * Output: "213"
 * Example 2:
 * Input: n = 4, k = 9
 * Output: "2314"
 * Example 3:
 * Input: n = 3, k = 1
 * Output: "123"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 1 <= k <= n!
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 0) return "";
        
        vector<int> f(n, 1);
        set<int> nums;
        nums.insert(n);
        for (int i = 1; i < n; i++) {
            f[i] = i * f[i - 1];
            nums.insert(i);
        }
        k--;
        string result;
        for (int i = n - 1; i >= 0; i--) {
            int idx = 0;
            if (f[i] <= k) {
                idx = k / f[i];
                k = k % f[i];
            }
            int num = *(next(nums.begin(), idx));
            result += ( num + '0');
            nums.erase(num);
        }
        return result;
    }
};
// @lc code=end

