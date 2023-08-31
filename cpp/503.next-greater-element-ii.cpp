/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (56.46%)
 * Likes:    1692
 * Dislikes: 73
 * Total Accepted:    103.7K
 * Total Submissions: 182.4K
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int length = nums.size();
        vector<int> solution(length, -1);
        
        for(int i = 0; i < 2 * length - 1; ++i)
        {
            int val = nums[i%length];
            while(!s.empty() && val > nums[s.top()])
            {
                solution[s.top()] = val;
                s.pop();
            }
            if(i < length)
                s.push(i%length);
        }
        return solution;
    }
};

// @lc code=end
// [1,1,1,1,1]
