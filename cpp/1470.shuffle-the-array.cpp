/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 *
 * https://leetcode.com/problems/shuffle-the-array/description/
 *
 * algorithms
 * Easy (88.40%)
 * Likes:    897
 * Dislikes: 103
 * Total Accepted:    153.8K
 * Total Submissions: 173.9K
 * Testcase Example:  '[2,5,1,3,4,7]\n3'
 *
 * Given the array nums consisting of 2n elements in the form
 * [x1,x2,...,xn,y1,y2,...,yn].
 * 
 * Return the array in the form [x1,y1,x2,y2,...,xn,yn].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,1,3,4,7], n = 3
 * Output: [2,3,5,4,1,7] 
 * Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is
 * [2,3,5,4,1,7].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4,4,3,2,1], n = 4
 * Output: [1,4,2,3,3,2,4,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,1,2,2], n = 2
 * Output: [1,2,1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 500
 * nums.length == 2n
 * 1 <= nums[i] <= 10^3
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(nums.size());
        int k = 0;
        for(int i=0; i<n; ++i)
        {
            for(int j=i; j<nums.size(); j+=n)
            {
                res[k++] = nums[j];
            }
        }
        return res;
    }
};
// @lc code=end
// [2,5,1,3,4,7]\n2
