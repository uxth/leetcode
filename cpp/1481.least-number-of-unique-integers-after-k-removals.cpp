/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 *
 * https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
 *
 * algorithms
 * Medium (53.76%)
 * Likes:    159
 * Dislikes: 14
 * Total Accepted:    16K
 * Total Submissions: 29.8K
 * Testcase Example:  '[5,5,4]\n1'
 *
 * Given an array of integers arr and an integer k. Find the least number of
 * unique integers after removing exactly k elements.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [5,5,4], k = 1
 * Output: 1
 * Explanation: Remove the single 4, only 5 is left.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [4,3,1,1,3,3,2], k = 3
 * Output: 2
 * Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3
 * will be left.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 10^9
 * 0 <= k <= arr.length
 * 
 */

// @lc code=start
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i : arr) ++m[i];
        int res = 0;
        vector<pair<int,int>> v(m.begin(), m.end());
        sort(v.begin(),v.end(),[](auto& a, auto& b){return a.second < b.second;});
        for(auto& i : v)
        {
            if(i.second > k) break;
            k-=i.second;
            res++;
        }
        return m.size() - res;
    }
};
// @lc code=end
//[4,3,1,1,3,3,2]\n3
//[1]\n1
// [2,1,1,3,3,3]\n3