/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Easy (41.93%)
 * Likes:    933
 * Dislikes: 676
 * Total Accepted:    205.2K
 * Total Submissions: 484.3K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * You are given a sorted unique integer array nums.
 * 
 * Return the smallest sorted list of ranges that cover all the numbers in the
 * array exactly. That is, each element of nums is covered by exactly one of
 * the ranges, and there is no integer x such that x is in one of the ranges
 * but not in nums.
 * 
 * Each range [a,b] in the list should be output as:
 * 
 * 
 * "a->b" if a != b
 * "a" if a == b
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: The ranges are:
 * [0,2] --> "0->2"
 * [4,5] --> "4->5"
 * [7,7] --> "7"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: The ranges are:
 * [0,0] --> "0"
 * [2,4] --> "2->4"
 * [6,6] --> "6"
 * [8,9] --> "8->9"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = []
 * Output: []
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [-1]
 * Output: ["-1"]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [0]
 * Output: ["0"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 20
 * -2^31 <= nums[i] <= 2^31 - 1
 * All the values of nums are unique.
 * nums is sorted in ascending order.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<string> summaryRanges(vector<int>& nums) {
    //     std::vector<std::string> result;
    //     for (auto left {nums.begin()}; left != nums.end(); ) {
    //         std::string value {std::to_string(*left)};
    //         auto right = std::adjacent_find(left, nums.end(), [](const auto& a, const auto& b) {
    //             return (a + 1) != b;
    //         });
    //         if (right == nums.end()) {
    //             --right;
    //         }
    //         if (left != right) {
    //             value += "->";
    //             value += std::to_string(*right);
    //         }
    //         result.push_back(value);
    //         left = right + 1;
    //     }
    //     return result;
    // }

    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0;
        vector<string> res;
        while (left < nums.size())
        {
            int length = 1;
            while (left + length < nums.size() && (long)nums[left + length] - nums[left] == length) length++;
            res.push_back(length == 1 ? to_string(nums[left]) : to_string(nums[left]) + "->" + to_string(nums[left + length - 1]));
            left += length;
        }
        return res;
    }
};
// @lc code=end
// [0,1,2,4,5,6,7]
// ]
