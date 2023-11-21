/*

Description
Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

There are at least 3 and at most 10,000 points.
Coordinates are in the range -10,000 to 10,000.
You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don’t intersect each other.
Example 1:

[[0,0],[0,1],[1,1],[1,0]]

Answer: True

Explanation:
Image text

Example 2:

[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

Explanation:
Image text

Solution
If a polygon is convex, then all interior angles are strictly less than 180 degrees. In other words, suppose there is an object traveling along the edges, starting from any point and finally going back to the starting point, then each time the object turns, it should turn in the same direction (always clockwise or always counterclockwise).

Suppose two edges have vectors (x1, y1) and (x2, y2) respectively, then the turning direction can be represented by x1 * y2 - x2 * y1. The positive result represents turning counterclockwise and the negative result represents turning clockwise.

If the turning direction is always the same, return true. Otherwise, return false.
*/

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long long pre = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points[(i + 1) % n][0] - points[i][0];
            int y1 = points[(i + 1) % n][1] - points[i][1];
            int x2 = points[(i + 2) % n][0] - points[i][0];
            int y2 = points[(i + 2) % n][1] - points[i][1];
            cur = 1L * x1 * y2 - x2 * y1;
            if (cur != 0) {
                if (cur * pre < 0) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
};