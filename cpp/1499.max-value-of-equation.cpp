/*
 * @lc app=leetcode id=1499 lang=cpp
 *
 * [1499] Max Value of Equation
 *
 * https://leetcode.com/problems/max-value-of-equation/description/
 *
 * algorithms
 * Hard (44.56%)
 * Likes:    153
 * Dislikes: 4
 * Total Accepted:    4.5K
 * Total Submissions: 10.1K
 * Testcase Example:  '[[1,3],[2,0],[5,10],[6,-10]]\n1'
 *
 * Given an array points containing the coordinates of points on a 2D plane,
 * sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all
 * 1 <= i < j <= points.length. You are also given an integer k.
 * 
 * Find the maximum value of the equation yi + yj + |xi - xj| where |xi - xj|
 * <= k and 1 <= i < j <= points.length. It is guaranteed that there exists at
 * least one pair of points that satisfy the constraint |xi - xj| <= k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
 * Output: 4
 * Explanation: The first two points satisfy the condition |xi - xj| <= 1 and
 * if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth
 * points also satisfy the condition and give a value of 10 + -10 + |5 - 6| =
 * 1.
 * No other pairs satisfy the condition, so we return the max of 4 and 1.
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[0,0],[3,0],[9,2]], k = 3
 * Output: 3
 * Explanation: Only the first two points have an absolute difference of 3 or
 * less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= points.length <= 10^5
 * points[i].length == 2
 * -10^8 <= points[i][0], points[i][1] <= 10^8
 * 0 <= k <= 2 * 10^8
 * points[i][0] < points[j][0] for all 1 <= i < j <= points.length
 * xi form a strictly increasing sequence.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq; // max-heap
        pq.push({points[0][1]-points[0][0],points[0][0]});
        int ans= INT_MIN;
        for(int i=1;i<points.size();i++) {
            int sum = points[i][0]+points[i][1];
            while(!pq.empty() && points[i][0]-pq.top().second>k) pq.pop();
            if(!pq.empty())ans = max(ans,sum+pq.top().first);
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }
};
// @lc code=end

