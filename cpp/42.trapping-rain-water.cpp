/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (48.82%)
 * Likes:    8130
 * Dislikes: 129
 * Total Accepted:    567.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int res = 0;
        int maxHeight = height[0];
        int heightIndex = distance(height.begin(), max_element(height.begin(), height.end()));

        for(int i=1; i<heightIndex; ++i)
        {
            if(height[i] < maxHeight) res+=maxHeight-height[i];
            else maxHeight = height[i];
        }
        maxHeight = height.back();
        for(int i=height.size()-2; i>heightIndex; --i)
        {
            if(height[i] < maxHeight) res+=maxHeight-height[i];
            else maxHeight=height[i];
        }
        return res;
    }
};
// @lc code=end

