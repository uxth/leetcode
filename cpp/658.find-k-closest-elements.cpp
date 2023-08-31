/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (40.86%)
 * Likes:    1526
 * Dislikes: 262
 * Total Accepted:    115.1K
 * Total Submissions: 280.1K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * Given a sorted array arr, two integers k and x, find the k closest elements
 * to x in the array. The result should also be sorted in ascending order. If
 * there is a tie, the smaller elements are always preferred.
 * 
 * 
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * Absolute value of elements in the array and x will not exceed 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i : arr)
        {
            q.push({abs(x-i), i});
        }
        vector<int> res;
        while(!q.empty() && k--)
        {
            res.push_back(q.top().second); 
            q.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
// [1,2,3,4,5]\n4\n-1
