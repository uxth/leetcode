/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 *
 * https://leetcode.com/problems/longest-turbulent-subarray/description/
 *
 * algorithms
 * Medium (46.62%)
 * Likes:    417
 * Dislikes: 93
 * Total Accepted:    31.1K
 * Total Submissions: 66.8K
 * Testcase Example:  '[9,4,2,10,7,8,8,1,9]'
 *
 * A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only
 * if:
 * 
 * 
 * For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is
 * even;
 * OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k
 * is odd.
 * 
 * 
 * That is, the subarray is turbulent if the comparison sign flips between each
 * adjacent pair of elements in the subarray.
 * 
 * Return the length of a maximum size turbulent subarray of A.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [9,4,2,10,7,8,8,1,9]
 * Output: 5
 * Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,8,12,16]
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [100]
 * Output: 1
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 40000
 * 0 <= A[i] <= 10^9
 * 
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int res = 0;
        for (auto i = 0, cnt = 0; i + 1 < A.size(); ++i, cnt *= -1) {
            if (A[i] > A[i + 1]) cnt = cnt > 0 ? cnt + 1 : 1;
            else if (A[i] < A[i + 1])  cnt = cnt < 0 ? cnt - 1 : -1;
            else cnt = 0;
            res = max(res, abs(cnt));
        }
        return res + 1;
    }
};
// @lc code=end
// [0,1,1,0,1,0,1,1,0,0]
