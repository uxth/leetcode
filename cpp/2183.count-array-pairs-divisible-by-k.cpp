/*
 * @lc app=leetcode id=2183 lang=cpp
 *
 * [2183] Count Array Pairs Divisible by K
 *
 * https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/
 *
 * algorithms
 * Hard (26.43%)
 * Likes:    784
 * Dislikes: 33
 * Total Accepted:    13.9K
 * Total Submissions: 48.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a 0-indexed integer array nums of length n and an integer k, return
 * the number of pairs (i, j) such that:
 * 
 * 
 * 0 <= i < j <= n - 1 and
 * nums[i] * nums[j] is divisible by k.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5], k = 2
 * Output: 7
 * Explanation: 
 * The 7 pairs of indices whose corresponding products are divisible by 2 are
 * (0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).
 * Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.
 * Other pairs such as (0, 2) and (2, 4) have products 3 and 15 respectively,
 * which are not divisible by 2.    
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4], k = 5
 * Output: 0
 * Explanation: There does not exist any pair of indices whose corresponding
 * product is divisible by 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map <int, int> gcdCount;
        long long cnt = 0;
        for (int num: nums) {
            int hcf = gcd(num, k);
            int required = k/hcf;
            for (auto& [key, value]: gcdCount) {
                if (key % required == 0) cnt += value;
            }
            gcdCount[hcf]++;
        }
        return cnt;
    }
};
// @lc code=end
/*
[1,2,3,4]\n5
[8,10,2,5,9,6,3,8,2]\n6
*/
