/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (43.66%)
 * Likes:    1201
 * Dislikes: 405
 * Total Accepted:    47.2K
 * Total Submissions: 107.9K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * Given an array nums sorted in ascending order, return true if and only if
 * you can split it into 1 or more subsequences such that each subsequence
 * consists of consecutive integers and has length at least 3.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3
 * 3, 4, 5
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,4,5]
 * Output: False
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10000
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // bool isPossible(vector<int>& nums) {
    //     unordered_map<int, int> left, end;
    //     for (int i: nums) {
    //         left[i]++;
    //     }
    //     for (int i: nums) {
    //         if (left[i] == 0) continue;
    //         left[i]--;
    //         if (end[i - 1] > 0) {   
    //             end[i - 1]--;
    //             end[i]++;
    //         } else if (left[i + 1] > 0 && left[i + 2] > 0) {
    //             left[i + 1]--;
    //             left[i + 2]--;
    //             end[i + 2]++;
    //         } else {   
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    bool isPossible(vector<int>& nums)
    {
        unordered_map<int, int> freq, need;
        for (int num : nums) ++freq[num];
        for (int num : nums) {
            if (freq[num] == 0) continue;
            if (need[num] > 0) {
                --need[num];
                ++need[num + 1];
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                --freq[num + 1];
                --freq[num + 2];
                ++need[num + 3];
            } else return false;
            --freq[num];
        }
        return true;
    }
};
// @lc code=end

