/*
 * @lc app=leetcode id=1390 lang=cpp
 *
 * [1390] Four Divisors
 *
 * https://leetcode.com/problems/four-divisors/description/
 *
 * algorithms
 * Medium (38.09%)
 * Likes:    81
 * Dislikes: 88
 * Total Accepted:    11.9K
 * Total Submissions: 31.2K
 * Testcase Example:  '[21,4,7]'
 *
 * Given an integer array nums, return the sum of divisors of the integers in
 * that array that have exactly four divisors.
 * 
 * If there is no such integer in the array, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [21,4,7]
 * Output: 32
 * Explanation:
 * 21 has 4 divisors: 1, 3, 7, 21
 * 4 has 3 divisors: 1, 2, 4
 * 7 has 2 divisors: 1, 7
 * The answer is the sum of divisors of 21 only.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> div(int n)
    {
        vector<int> res;
        int a = 1;
        while(a < n/a)
        {
            if(n%a==0){res.push_back(a), res.push_back(n/a);}
            a++;
        }
        if(n%a==0 && a==n/a){res.push_back(a);}
        return res;
    }
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int n : nums)
        {
            auto d = div(n);
            if(d.size()==4) res+=accumulate(d.begin(), d.end(), 0);
        }
        return res;
    }
};
// @lc code=end

