/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (50.48%)
 * Likes:    261
 * Dislikes: 542
 * Total Accepted:    55.3K
 * Total Submissions: 109.5K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> m;
        for(int i=0; i<nums.size(); ++i)
        {
            m.push_back({nums[i], i});
        }
        sort(m.begin(), m.end(), [](pair<int,int>& a, pair<int,int>& b){return a.first > b.first;});
        vector<string> res(nums.size());
        for(int i=0; i<m.size(); ++i)
        {
            if(i==0)
                res[m[i].second] = "Gold Medal";
            else if(i==1)
                res[m[i].second] = "Silver Medal";
            else if(i==2)
                res[m[i].second] = "Bronze Medal";
            else
                res[m[i].second] = to_string(i+1);
        }
        return res;
    }
};
// @lc code=end

