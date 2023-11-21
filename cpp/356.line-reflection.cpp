/*

Question
Formatted question description: https://leetcode.ca/all/356.html

Given n points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points symmetrically.

In other words, answer whether or not if there exists a line that after reflecting all points over the given line, the original points' set is the same as the reflected ones.

Note that there can be repeated points.

 

Example 1:



Input: points = [[1,1],[-1,1]]
Output: true
Explanation: We can choose the line x = 0.
Example 2:



Input: points = [[1,1],[-1,-1]]
Output: false
Explanation: We can't choose a line.
 

Constraints:

n == points.length
1 <= n <= 104
-108 <= points[i][j] <= 108
 

Follow up: Could you do better than O(n2)?

Algorithm
The hints in the question are quite adequate, we just need to follow the hinted steps to solve the problem.

First, we find the maximum and minimum values of the abscissa of all points, then the average of the two is the abscissa of the middle straight line,
Then we traverse each point, and if we can find another point that is symmetrical in a straight line, we return true, otherwise we return false

*/

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        const int inf = 1 << 30;
        int minX = inf, maxX = -inf;
        set<pair<int, int>> pointSet;
        for (auto& p : points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            pointSet.insert({p[0], p[1]});
        }
        int s = minX + maxX;
        for (auto& p : points) {
            if (!pointSet.count({s - p[0], p[1]})) {
                return false;
            }
        }
        return true;
    }
};