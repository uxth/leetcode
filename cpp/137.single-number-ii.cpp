/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (52.36%)
 * Likes:    1962
 * Dislikes: 368
 * Total Accepted:    255.7K
 * Total Submissions: 485.8K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */

// @lc code=start
class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     unordered_set<int> once, twice;
    //     for(int i:nums)
    //     {
    //         if(twice.count(i)) continue;
    //         if(once.count(i)){once.erase(i); twice.insert(i);}
    //         else once.insert(i);
    //     }
    //     return *once.begin();
    // }
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; ++i)
        {
            int count = 0;
            for(int n : nums)
                count += (n & 1<<i) != 0;
            
            if(count % 3) res |= (1 << i);
        }
        return res;
    
    }
};
// @lc code=end
// [1,1,1,-5,-5,-5,6]
