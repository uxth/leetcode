/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (41.50%)
 * Likes:    796
 * Dislikes: 121
 * Total Accepted:    83.6K
 * Total Submissions: 200.9K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * Given an array consisting of n integers, find the contiguous subarray of
 * given length k that has the maximum average value. And you need to output
 * the maximum average value.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int res = INT_MIN;
        for(int i=0; i<nums.size(); ++i)
        {
            sum += i-k>=0 ? nums[i] - nums[i-k] : nums[i];
            if (i - k >= - 1) res = max(res, sum);
        }
        return (double)res / k;
    }
};
// @lc code=end
// [-1]\n1
// [-6662,5432,-8558,-8935,8731,-3083,4115,9931,-4006,-3284,-3024,1714,-2825,-2374,-2750,-959,6516,9356,8040,-2169,-9490,-3068,6299,7823,-9767,5751,-7897,6680,-1293,-3486,-6785,6337,-9158,-4183,6240,-2846,-2588,-5458,-9576,-1501,-908,-5477,7596,-8863,-4088,7922,8231,-4928,7636,-3994,-243,-1327,8425,-3468,-4218,-364,4257,5690,1035,6217,8880,4127,-6299,-1831,2854,-4498,-6983,-677,2216,-1938,3348,4099,3591,9076,942,4571,-4200,7271,-6920,-1886,662,7844,3658,-6562,-2106,-296,-3280,8909,-8352,-9413,3513,1352,-8825]\n90