/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (21.71%)
 * Likes:    855
 * Dislikes: 50
 * Total Accepted:    241.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * You are given an integer array nums and two integers indexDiff and
 * valueDiff.
 * 
 * Find a pair of indices (i, j) such that:
 * 
 * 
 * i != j,
 * abs(i - j) <= indexDiff.
 * abs(nums[i] - nums[j]) <= valueDiff, and
 * 
 * 
 * Return true if such pair exists or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
 * Output: true
 * Explanation: We can choose (i, j) = (0, 3).
 * We satisfy the three conditions:
 * i != j --> 0 != 3
 * abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
 * abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
 * Output: false
 * Explanation: After trying all the possible pairs (i, j), we cannot satisfy
 * the three conditions, so we return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 1 <= indexDiff <= nums.length
 * 0 <= valueDiff <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int,int>> data;
        for(int i=0; i<nums.size(); ++i){
            data.push_back({nums[i], i});
        }
        sort(begin(data), end(data));
        for(int i=0; i<data.size(); ++i){
            for(int j=i+1; j<data.size() && data[j].first-data[i].first<=valueDiff && data[j].first-data[i].first>=-valueDiff; ++j){
                if(data[j].second - data[i].second <= indexDiff && data[j].second - data[i].second >= -indexDiff) return true;
            }
        }
        return false;
    }
};
// @lc code=end
/*
[1,2,3,1]\n3\n0
*/
