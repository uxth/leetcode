/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 *
 * https://leetcode.com/problems/heaters/description/
 *
 * algorithms
 * Easy (33.14%)
 * Likes:    765
 * Dislikes: 867
 * Total Accepted:    67.5K
 * Total Submissions: 203.2K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * Winter is coming! Your first job during the contest is to design a standard
 * heater with fixed warm radius to warm all the houses.
 * 
 * Now, you are given positions of houses and heaters on a horizontal line,
 * find out minimum radius of heaters so that all houses could be covered by
 * those heaters.
 * 
 * So, your input will be the positions of houses and heaters seperately, and
 * your expected output will be the minimum radius standard of heaters.
 * 
 * Note:
 * 
 * 
 * Numbers of houses and heaters you are given are non-negative and will not
 * exceed 25000.
 * Positions of houses and heaters you are given are non-negative and will not
 * exceed 10^9.
 * As long as a house is in the heaters' warm radius range, it can be
 * warmed.
 * All the heaters follow your radius standard and the warm radius will the
 * same.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3],[2]
 * Output: 1
 * Explanation: The only heater was placed in the position 2, and if we use the
 * radius 1 standard, then all the houses can be warmed.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4],[1,4]
 * Output: 1
 * Explanation: The two heater was placed in the position 1 and 4. We need to
 * use radius 1 standard, then all the houses can be warmed.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int minRadius = 0;
        for (int i = 0; i < houses.size(); i++) {
            // search for the closest heater whose position is at least the current house's position
            auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            int curRadius = INT_MAX;
            // if there is such a heater, update the radius for that heater to cover this house if necessary
            if (larger != heaters.end())
                curRadius = *larger - houses[i];
            // if the heater we found is not the first one, then the previous heater is the closest heater
            // whose position is smaller than the current house's position
            if (larger != heaters.begin()) {
                auto smaller = larger - 1;
            // the heater with the smaller required radius to cover the house wins
                curRadius = min(curRadius, houses[i] - *smaller);
            }
            minRadius = max(minRadius, curRadius);
        }
        return minRadius;
    }
};
// @lc code=end
// [1,2,3,4]\n[1,4]
