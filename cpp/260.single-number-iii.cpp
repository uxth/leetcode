/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (65.21%)
 * Likes:    2132
 * Dislikes: 128
 * Total Accepted:    184.3K
 * Total Submissions: 282.2K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 * 
 * Follow up: Your algorithm should run in linear runtime complexity. Could you
 * implement it using only constant space complexity?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,0]
 * Output: [-1,0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,1]
 * Output: [1,0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        int element1=0, element2=0;
        //loop all the element and xor them with zero, all those element that appear twice will yield 0 and result will be just xor of element taht appear once
        for(int i=0;i<nums.size();i++)
            x^=nums[i];
        x = x&(-x);  //get the last set bit
        //now we loop and separate elements with set bit as x and other        
        for(int i=0;i<nums.size();i++){
            if(nums[i]& x)  
                element1^=nums[i]; //here we will be left with only that element has set bit x and appear once
            else 
                element2^= nums[i]; //the other element that appear as once and has not set bit x
        }
        return {element1, element2};
    }
};
// @lc code=end

